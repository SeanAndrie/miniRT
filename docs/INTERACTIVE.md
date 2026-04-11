# Interactive Controls

## Overview

miniRT provides real-time interactive controls for manipulating the scene. When running, press keys or use the mouse to modify camera position, selected objects, or lights.

## Keyboard Controls

### Movement

| Key | Action |
|-----|-------|
| `W` | Move forward |
| `S` | Move backward |
| `A` | Strafe left |
| `D` | Strafe right |
| `Space` | Move up |
| `Ctrl` | Move down |

### Rotation

| Key | Action |
|-----|-------|
| `Q` | Rotate left (yaw) |
| `E` | Rotate right (yaw) |

Hold `Shift` for faster rotation.

### Property Modes

| Key | Mode |
|-----|------|
| `P` | Position mode |
| `H` | Hue/color mode |
| `T` | Transform mode |

### Light Selection

| Key | Action |
|-----|-------|
| `L` | Cycle through lights |
| `N` | Next light |
| `Keypad +/-` | Adjust light intensity |

### Other Controls

| Key | Action |
|-----|-------|
| `R` | Reset scene to initial state |
| `U` | Toggle UI overlay |
| `ESC` | Exit application |

## Mouse Controls

| Button | Action |
|--------|-------|
| Left Click | Select object at cursor |
| Right Click | Context menu |
| Scroll Up | Zoom in |
| Scroll Down | Zoom out |

## Property Modes

### Position Mode (P)

Manipulate object position in 3D space using movement keys.

### Hue Mode (H)

Adjust object color. Current color is shown in UI.

### Transform Mode (T)

Apply transformation matrix (rotation/scale).

## UI Overlay

Press `U` to toggle an on-screen display:

```
+------------------------------------------+
|  FILE: 01_mandatory_basic.rt         |
|  OBJECTS: 3                      |
|  LIGHTS: 1                      |
|  SELECTED: sphere (0,0,10) r=6    |
|  POSITION: X=0 Y=0 Z=10          |
+------------------------------------------+
```

## Implementation

### Event Handling

```
src/context/
├── hooks/handle/
│   ├── handle_keypress.c    # Key down events
│   ├── handle_keyrelease.c  # Key up events
│   └── handle_mousepress.c # Mouse button events
├── hooks/dispatch/
│   ├── dispatch_translate.c   # Movement dispatch
│   ├── dispatch_rotate.c  # Rotation dispatch
│   └── dispatch_property.c  # Property changes
└── hooks/tween/
    ├── tween_lerp_update.c  # Linear interpolation
    └── tween_slerp_update.c # Spherical interpolation
```

### Tween System

Smooth animations using linear interpolation (LERP) and spherical LERP (SLERP):

```c
typedef struct s_tween
{
    t_vec3 *curr;       // Current position
    t_vec3 target;     // Target position
    t_bool (*update)(t_tween *tw, float t);  // Interpolation function
} t_tween;
```

## Configuration

Tweaking parameters in `includes/config.h`:

```c
#define TWEEN_FACTOR  0.2f   // Interpolation factor
#define TRANS_SPEED  1.2f   // Translation speed
#define ROTATE_ANGLE 0.2f    // Rotation angle per key
#define PROP_INCREMENT 0.5f   // Property increment
```