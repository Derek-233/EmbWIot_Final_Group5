import numpy as np
from scipy.optimize import least_squares

H = 1.2  # height difference between board and tag (metres)

data = {
    7:  {'board': (141,  110), 'az': -28.95, 'el': -54.98},
    8:  {'board': (141,  310), 'az': -52.35, 'el':  -6.72},
    9:  {'board': (63,   466), 'az': -14.43, 'el':  53.14},
    10: {'board': (-187, 366), 'az':  45.71, 'el':  16.49},
    11: {'board': (-237, 266), 'az':  44.14, 'el': -21.10},
    12: {'board': (-112, 116), 'az':  28.74, 'el': -30.33},
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

print("=" * 55)
print("Least Squares Tag Localization — Points 7-12")
print("=" * 55)
print(f"Estimated tag:     ({tx_est:.1f}, {ty_est:.1f}) cm")
print(f"Ground truth:      (0.0, 300.0) cm")
print(f"Error X:           {tx_est - 0:+.1f} cm")
print(f"Error Y:           {ty_est - 300:+.1f} cm")
error_dist = np.sqrt((tx_est)**2 + (ty_est - 300)**2)
print(f"Euclidean error:   {error_dist:.1f} cm  ({error_dist/100:.3f} m)")
print()
print("Per-point residuals (perpendicular distance to ray):")
res = residuals([tx_est, ty_est], data, H)
for p, r in zip(data.keys(), res):
    print(f"  point{p:<3}: {r:.1f} cm")
print(f"  Mean residual: {np.mean(res):.1f} cm")
