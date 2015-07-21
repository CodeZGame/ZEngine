# ZEngine

ZEngine is 2D game engine based on top of SFML (with an idea of abstraction, which will next lead to the possibility of using another low-level library).

The engine will be separated in different modules. Currently only the basic core is working.
In the future the engine will have several module based on the real need for game development (Animation, Collisions, AI, pathfinding, GUI, Particle System, "Debugs" ...)


--- Common usage of the engine ---

This is a list a common rules to properly use the engine (no particular order):

- If you didn't "new" an object, you don't have to "delete" it ! For instance, calling a Create**** , you got a new object in return, but you don't care about freeing it (unless you want to specifically delete this object, when changing level for example, you can call the Release*** with the object you want to release).
