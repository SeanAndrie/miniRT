# Threading Model

## Overview

miniRT uses a tile-based worker pool to parallelize raytracing across multiple threads.

## Configuration

Defined in `includes/config.h`:

```c
#define MULTITHREADED TRUE
#define N_THREADS    8
#define N_TILES      256     // Used to calculate tile dimensions
```

## Architecture

```
┌─────────────────────────────────────────┐
│              Main Thread                │
│  context_loop()                         │
│  ├─ render_init() → pool_init()         │
│  ├─ mlx_loop()                          │
│  └─ Handle events (keyboard/mouse)      │
└─────────────────────────────────────────┘
                    │
                    ▼ (render triggered)
┌─────────────────────────────────────────┐
│           Worker Threads                │
│  pool_run()                             │
│  ├─ Worker 0: tiles[0..31]              │
│  ├─ Worker 1: tiles[32..63]             │
│  ├─ Worker 2: tiles[64..95]             │
│  ├─ ...                                 │
│  └─ Worker 7: tiles[224..255]           │
└─────────────────────────────────────────┘
```

## Tile Division

The frame is divided into tiles for parallel processing:

- **Default canvas**: 800x600 pixels
- **Tile size**: Configured via `tile_dim` based on frame dimensions
- **Total tiles**: Computed dynamically based on canvas size (width/tile_w × height/tile_h)

Actually computed dynamically based on canvas dimensions.

## Data Structures

### t_pool

```c
typedef struct s_pool
{
    t_tile     *tiles;        // Array of tiles
    size_t     n_tiles;     // Total tiles
    size_t     n_workers;   // Number of workers (8)
    t_worker  **workers;    // Worker array
    size_t     worker_tiles; // Tiles per worker
} t_pool;
```

### t_worker

```c
typedef struct s_worker
{
    t_tile    *tiles;    // Tile array reference
    t_scene   *scene;    // Scene reference
    pthread_t thread;   // Thread handle
    size_t    start;    // First tile index
    size_t    end;      // One-past last tile index
} t_worker;
```

### t_tile

```c
typedef struct s_tile
{
    t_tensr *rdir;     // Ray directions for tile
    t_tensr *buffer;   // Color output buffer
    int     width;     // Tile width
    int     height;    // Tile height
} t_tile;
```

## Workflow

### Initialization (`pool_init.c`)

```c
t_bool pool_init(t_pool *pool, t_display *disp, t_scene *scene)
{
    // 1. Calculate tile count
    pool->n_tiles = disp->frame.tile_dim.count;
    
    // 2. Create tiles with ray directions
    create_tiles(pool->tiles, disp, scene->cam.rdir.out);
    
    // 3. Distribute tiles to workers
    pool->worker_tiles = pool->n_tiles / pool->n_workers;
    create_workers(pool, scene);
}
```

### Execution (`pool_run.c`)

```c
t_bool pool_run(t_pool *pool)
{
    size_t i;
    
    i = 0;
    while (i < pool->n_workers)
    {
        // Launch worker thread
        pthread_create(&pool->workers[i]->thread, NULL,
                       worker_routine, pool->workers[i]);
        i++;
    }
}
```

### Worker Routine

Each worker:
1. Iterates over assigned tiles
2. For each pixel in tile, trace ray and shade
3. Writes to shared framebuffer
4. Exits (joins in `pool_join`)

### Synchronization

- Workers write to **independent tile regions** of the framebuffer
- No synchronization needed during rendering
- Main thread joins all workers before blitting

## Performance

With 8 threads:
- Theoretical 8x speedup for pure rendering
- Actual speedup ~4-6x due to:
  - Thread creation overhead
  - Memory contention
  - Scene data access patterns
  - Main thread synchronization

## Key Files

| File | Purpose |
|------|---------|
| `src/render/pool/pool_init.c` | Pool and worker initialization |
| `src/render/pool/pool_run.c` | Thread launch |
| `src/render/pool/pool_join.c` | Thread synchronization |
| `src/render/pool/pool_join.c` | Cleanup |
| `src/render/tile/tile_create.c` | Tile creation |
