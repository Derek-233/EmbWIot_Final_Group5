import numpy as np

def convert_aoa(az_deg, el_deg):
    """
    Convert original AoA (az, el) in +-90 deg range
    to new (az_new, el_new) in +-180 deg range.

    Board frame: +Y = boresight, +X = right, +Z = up
    """
    az = np.radians(az_deg)
    el = np.radians(el_deg)

    # Step 1: 3D unit vector in board frame
    vx = np.sin(az) * np.cos(el)
    vy = np.cos(az) * np.cos(el)   # boresight component
    vz = np.sin(el)

    # Step 2: new azimuth (+-180 deg) in XZ plane
    az_new = np.degrees(np.arctan2(vx, vz))

    # Step 3: new elevation — angle from XZ plane toward boresight
    el_new = np.degrees(np.arctan2(vy, np.sqrt(vx**2 + vz**2)))

    return az_new, el_new


if __name__ == '__main__':
    # Example usage
    test_cases = [
        ( 0,    0),
        (90,    0),
        (-90,   0),
        ( 0,   90),
        ( 0,  -90),
        (45,   45),
        (-28.95, -54.98),
    ]
    print(f"{'Az_orig':>10} {'El_orig':>10} | {'Az_new':>10} {'El_new':>10}")
    print('-' * 48)
    for az, el in test_cases:
        az_n, el_n = convert_aoa(az, el)
        print(f"{az:>9.2f}° {el:>9.2f}° | {az_n:>9.2f}° {el_n:>9.2f}°")
