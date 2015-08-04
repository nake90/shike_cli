# shike client
Client interface for shike, a 3D cloud point generator of buildings and objects
from pictures and videos.

Currently for Linux, Mac and Windows, but in the near future it should work too
for Android and maybe iOS, althought it's being developed on linux and I have
not tested it under other platforms yet.

## Compiling
You'll need [OpenFrameworks](http://openframeworks.cc) installed and the
following addons: ofxGui, ofxNetwork, ofxXmlSettings (they come by default in
OF).

To compile place the project in the *apps/myApps/* of your openFrameworks root
folder. *myApps* could be any folder you like.

Then type `make` in a terminal. The executable will be placed in *bin/*, and you
execute it with `make run` or by running `cd bin/ && ./shike_cli`.

To build the debug version use `make Debug` instead.
