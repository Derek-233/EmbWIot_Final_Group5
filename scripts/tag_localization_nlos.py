import numpy as np
from scipy.optimize import least_squares

H = 1.2

# Points 13-18: NLOS, tag ground truth at (-318, 285) cm
data = {
    13: {'board': (141,  110), 'az': -64.25, 'el': -20.66},
    14: {'board': (141,  310), 'az':  -0.86, 'el':  -5.82},
    15: {'board': (63,   466), 'az': -54.84, 'el':  16.85},
    16: {'board': (-187, 366), 'az': -66.40, 'el':  18.01},
    17: {'board': (-237, 266), 'az': -54.48, 'el':  -6.13},
    18: {'board': (-112, 116), 'az': -46.28, 'el': -28.30},
}

def ray_direction(az_deg, el_deg):
    az = np.radians(az_deg)
    el = np.radians(el_deg)
    vx_b = np.sin(az) * np.cos(el)
    vy_b = np.cos(az) * np.cos(el)
    vz_b = np.sin(el)
    dx = vx_b
    dy = -vz_b
    dz = vy_b
    return np.array([dx, dy, dz])

def residuals(tag_xy, data, H):
    tx, ty = tag_xy
    tz = H * 100
    res = []
    for p, d in data.items():
        bx, by = d['board']
        origin    = np.array([bx, by, 0.0])
        direction = ray_direction(d['az'], d['el'])
        direction = direction / np.linalg.norm(direction)
        tag       = np.array([tx, ty, tz])
        diff      = tag - origin
        dist      = np.linalg.norm(np.cross(diff, direction))
        res.append(dist)
    return res

boards = np.array([d['board'] for d in data.values()])
x0 = boards.mean(axis=0)

result = least_squares(residuals, x0, args=(data, H))
tx_est, ty_est = result.x

gt_x, gt_y = -318, 285

print("=" * 55)
print("Least Squares Tag Localization — Points 13-18 (NLOS)")
print("=" * 55)
print(f"Estimated tag:     ({tx_est:.1f}, {ty_est:.1f}) cm")
print(f"Ground truth:      ({gt_x}, {gt_y}) cm")
print(f"Error X:           {tx_est - gt_x:+.1f} cm")
print(f"Error Y:           {ty_est - gt_y:+.1f} cm")
error_dist = np.sqrt((tx_est - gt_x)**2 + (ty_est - gt_y)**2)
print(f"Euclidean error:   {error_dist:.1f} cm  ({error_dist/100:.3f} m)")
print()
print("Per-point residuals (perpendicular distance to ray):")
res = residuals([tx_est, ty_est], data, H)
for p, r in zip(data.keys(), res):
    print(f"  point{p:<3}: {r:.1f} cm")
print(f"  Mean residual: {np.mean(res):.1f} cm")
print()
print("=" * 55)
print("LOS vs NLOS Comparison")
print("=" * 55)
print(f"  LOS  (pt7-12):  Euclidean error = 10.1 cm (0.101 m)")
print(f"  NLOS (pt13-18): Euclidean error = {error_dist:.1f} cm ({error_dist/100:.3f} m)")
