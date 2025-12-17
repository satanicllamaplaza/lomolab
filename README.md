# libraries
* Opencv (intermediat)
* libvips (expert)

# Struct concepts
* Store the original image as immutable and apply all edits non-destructively to a working pipeline.
* Represent edits as an ordered filter stack, not a single flat parameter struct.
* Each filter is a small POD-style struct containing only its parameters and no dynamic memory.
* Filter order is defined by the index position in a vector, not by struct layout.
* Use std::variant (or equivalent) to store multiple filter parameter types in a single filter container.
* Reordering the filter stack directly changes the visual output due to non-commutative image operations.
* Rendering is done by iterating the filter stack in order and applying each filter sequentially.
* Undo/redo is implemented by snapshotting filter stack states rather than pixel buffers.
* Presets (“recipes”) are serialized representations of the filter stack and its parameters.
* Batch processing reuses the same filter stack renderer in a headless (non-interactive) mode.

# UI
* ncurses / ncursesw

## UI architecture rule (important)
### UI never touches image data.
### UI responsibilities:
* Display filter stack
* Handle input
* Modify filter stack data
### Renderer responsibilities:
* Read filter stack
* Produce image
* Emit Kitty graphics
### This separation keeps everything sane.


when program opens it opens with an empty filter stack.

* hjkl is to go up and down in filters and left and right to increase filter strength

* a = add filter
* s = save as
* S = save


* y = copy (filter)
* p = paste filter after
* P = paste filter before
* x = copy filter
* d = delete filter


* u = undo last change
* U = undo till last save
* q = quit
