Preferences
===========

General
-------

**Always check for updates on start-up**

When checked, Natron will check for new updates on start-up of the application.

**Enable crash reporting**

When checked, if Natron crashes a window will pop-up asking you whether you want to upload the crash dump to the developers or not. This can help them track down the bug. If you need to turn the crash reporting system off, uncheck this. Note that when using the application in command-line mode, if crash reports are enabled, they will be automatically uploaded. Changing this requires a restart of the application to take effect.

**Test Crash Reporting**

This button is for developers only to test whether the crash reporting system works correctly. Do not use this.

**Auto-save trigger delay**

The number of seconds after an event that Natron should wait before auto-saving. Note that if a render is in progress, Natron will wait until it is done to actually auto-save.

**Enable Auto-save for unsaved projects**

When activated Natron will auto-save projects that have never been saved and will prompt you on startup if an auto-save of that unsaved project was found. Disabling this will no longer save un-saved project.

**Appear to plug-ins as**

Natron will appear with the name of the selected application to the OpenFX plug-ins. Changing it to the name of another application can help loading plugins which restrict their usage to specific OpenFX host(s). If a Host is not listed here, use the "Custom" entry to enter a custom host name. Changing this requires a restart of the application and requires clearing the OpenFX plugins cache from the Cache menu.

Threading
---------

**Number of render threads (0="guess")**

Controls how many threads Natron should use to render. -1: Disable multithreading totally (useful for debugging) 0: Guess the thread count from the number of cores. The ideal threads count for this hardware is 8.

**Number of parallel renders (0="guess")**

Controls the number of parallel frame that will be rendered at the same time by the renderer.A value of 0 indicate that Natron should automatically determine the best number of parallel renders to launch given your CPU activity. Setting a value different than 0 should be done only if you know what you're doing and can lead in some situations to worse performances. Overall to get the best performances you should have your CPU at 100% activity without idle times.

**Effects use thread-pool**

When checked, all effects will use a global thread-pool to do their processing instead of launching their own threads. This suppresses the overhead created by the operating system creating new threads on demand for each rendering of a special effect. As a result of this, the rendering might be faster on systems with a lot of cores (>= 8). WARNING: This is known not to work when using The Foundry's Furnace plug-ins (and potentially some other plug-ins that the dev team hasn't not tested against it). When using these plug-ins, make sure to uncheck this option first otherwise it will crash Natron.

**Max threads usable per effect (0="guess")**

Controls how many threads a specific effect can use at most to do its processing. A high value will allow 1 effect to spawn lots of thread and might not be efficient because the time spent to launch all the threads might exceed the time spent actually processing.By default (0) the renderer applies an heuristic to determine what's the best number of threads for an effect.

**Render in a separate process**

If true, Natron will render frames to disk in a separate process so that if the main application crashes, the render goes on.

**Append new renders to queue**

When checked, renders will be queued in the Progress Panel and will start only when all other prior tasks are done.

Rendering
---------

**Convert NaN values**

When activated, any pixel that is a Not-a-Number will be converted to 1 to avoid potential crashes from downstream nodes. These values can be produced by faulty plug-ins when they use wrong arithmetic such as division by zero. Disabling this option will keep the NaN(s) in the buffers: this may lead to an undefined behavior.

**Copy input image before rendering any plug-in**

If checked, when before rendering any node, Natron will copy the input image to a local temporary image. This is to work-around some plug-ins that write to the source image, thus modifying the output of the node upstream in the cache. This is a known bug of an old version of RevisionFX REMap for instance. By default, this parameter should be leaved unchecked, as this will require an extra image allocation and copy before rendering any plug-in.

**RGB components support**

When checked Natron is able to process images with only RGB components (support for images with RGBA and Alpha components is always enabled). Un-checking this option may prevent plugins that do not well support RGB components from crashing Natron. Changing this option requires a restart of the application.

**Transforms concatenation support**

When checked Natron is able to concatenate transform effects when they are chained in the compositing tree. This yields better results and faster render times because the image is only filtered once instead of as many times as there are transformations.

GPU Rendering
-------------

**Active OpenGL Renderer**

The currently active OpenGL renderer

**Choose OpenGL Renderer**

Select the renderer that will be used to perform OpenGL rendering. Changing the OpenGL renderer requires a restart of the application.

**Num. OpenGL Context**

This is the number of OpenGL contexts that will be created to perform OpenGL rendering. Each OpenGL context can be attached to a CPU thread allowing for more frames to be rendered concurrently. Increasing the value of this parameter may increase performances for graphs with mixed CPU/GPU nodes but can drastically reduce performances if too many OpenGL contexts are active at once.

**OpenGL Rendering**

Select whether to activate OpenGL rendering or not. If disabled, even though a Project enable GPU rendering, it will not be activated.

Project Setup
-------------

**First image read set project format**

If checked, the first image you read in the project sets the project format to the image size.

**Auto-preview enabled by default for new projects**

If checked, then when creating a new project, the Auto-preview option is enabled.

**Auto fix relative file-paths**

If checked, when a project-path changes (either the name or the value pointed to), Natron checks all file-path parameters in the project and tries to fix them.

**Use drive letters instead of server names (Windows only)**

This is only relevant for Windows: If checked, Natron will not convert a path starting with a drive letter from the file dialog to a network share name. You may use this if for example you want to share a same project with several users across facilities with different servers but where users have all the same drive attached to a server.

Documentation
-------------

**Documentation Source**

Documentation source.

**Documentation local port (0=auto)**

The port onto which the documentation server will listen to. A value of 0 indicate that the documentation should automatically find a port by itself.

User Interface
--------------

**Warn when a file changes externally**

When checked, if a file read from a file parameter changes externally, a warning will be displayed on the viewer. Turning this off will suspend the notification system.

**Prompt with file dialog when creating Write node**

When checked, opens-up a file dialog when creating a Write node

**Refresh viewer only when editing is finished**

When checked, the viewer triggers a new render only when mouse is released when editing parameters, curves or the timeline. This setting doesn't apply to roto splines editing.

**Linear color pickers**

When activated, all colors picked from the color parameters are linearized before being fetched. Otherwise they are in the same colorspace as the viewer they were picked from.

**Maximum number of open settings panels (0="unlimited")**

This property holds the maximum number of settings panels that can be held by the properties dock at the same time.The special value of 0 indicates there can be an unlimited number of panels opened.

**Value increments based on cursor position**

When enabled, incrementing the value fields of parameters with the mouse wheel or with arrow keys will increment the digits on the right of the cursor. When disabled, the value fields are incremented given what the plug-in decided it should be. You can alter this increment by holding Shift (x10) or Control (/10) while incrementing.

**Default layout file**

When set, Natron uses the given layout file as default layout for new projects. You can export/import a layout to/from a file from the Layout menu. If empty, the default application layout is used.

**Load workspace embedded within projects**

When checked, when loading a project, the workspace (windows layout) will also be loaded, otherwise it will use your current layout.

Color-Management
----------------

**OpenColorIO config**

Select the OpenColorIO configuration you would like to use globally for all operators and plugins that use OpenColorIO, by setting the "OCIO" environment variable. Only nodes created after changing this parameter will take it into account, and it is better to restart the application after changing it. When "Custom config" is selected, the "Custom OpenColorIO config file" parameter is used.

**Custom OpenColorIO config file**

OpenColorIO configuration file (\*.ocio) to use when "Custom config" is selected as the OpenColorIO config.

**Warn on OpenColorIO config change**

Show a warning dialog when changing the OpenColorIO config to remember that a restart is required.

Caching
-------

**Aggressive caching**

When checked, Natron will cache the output of all images rendered by all nodes, regardless of their "Force caching" parameter. When enabling this option you need to have at least 8GiB of RAM, and 16GiB is recommended. If not checked, Natron will only cache the nodes which have multiple outputs, or their parameter "Force caching" checked or if one of its output has its settings panel opened.

**Maximum amount of RAM memory used for caching (% of total RAM)**

This setting indicates the percentage of the total RAM which can be used by the memory caches. This system has 23.37 GB of RAM.

**System RAM to keep free (% of total RAM)**

This determines how much RAM should be kept free for other applications running on the same system. When this limit is reached, the caches start recycling memory instead of growing. This value should reflect the amount of memory you want to keep available on your computer for other usage. A low value may result in a massive slowdown and high disk usage.

**Maximum playback disk cache size (GiB)**

The maximum size that may be used by the playback cache on disk (in GiB)

**Maximum DiskCache node disk usage (GiB)**

The maximum size that may be used by the DiskCache node on disk (in GiB)

**Disk cache path (empty = default)**

WARNING: Changing this parameter requires a restart of the application. This is points to the location where Natron on-disk caches will be. This variable should point to your fastest disk. If the parameter is left empty or the location set is invalid, the default location will be used. The default location is: /home/olear/.cache/INRIA/Natron

**Wipe Disk Cache**

Cleans-up all caches, deleting all folders that may contain cached data. This is provided in case Natron lost track of cached images for some reason.

Viewer
------

**Viewer textures bit depth**

Bit depth of the viewer textures used for rendering. Hover each option with the mouse for a detailed description.

**Viewer tile size is 2 to the power of...**

The dimension of the viewer tiles is 2^n by 2^n (i.e. 256 by 256 pixels for n=8). A high value means that the viewer renders large tiles, so that rendering is done less often, but on larger areas.

**Checkerboard tile size (pixels)**

The size (in screen pixels) of one tile of the checkerboard.

**Checkerboard color 1**

The first color used by the checkerboard.

**Checkerboard color 2**

The second color used by the checkerboard.

**Automatically enable wipe**

When checked, the wipe tool of the viewer will be automatically enabled when the mouse is hovering the viewer and changing an input of a viewer.

**Automatically enable proxy when scrubbing the timeline**

When checked, the proxy mode will be at least at the level indicated by the auto-proxy parameter.

**Max. opened node viewer interface**

Controls the maximum amount of nodes that can have their interface showing up at the same time in the viewer

**Use number keys for the viewer**

When enabled, the row of number keys on the keyboard is used for switching input ( connects input to A side, connects input to B side), even if the corresponding character in the current keyboard layout is not a number. This may have to be disabled when using a remote display connection to Linux from a different OS.

Nodegraph
---------

**Auto Scroll**

When checked the node graph will auto scroll if you move a node outside the current graph view.

**Auto-turbo**

When checked the Turbo-mode will be enabled automatically when playback is started and disabled when finished.

**Snap to node**

When moving nodes on the node graph, snap to positions where they are lined up with the inputs and output nodes.

**Use connection hints**

When checked, moving a node which is not connected to anything to arrows nearby displays a hint for possible connections. Releasing the mouse when hints are shown connects the node.

**Maximum undo/redo for the node graph**

Set the maximum of events related to the node graph Natron remembers. Past this limit, older events will be deleted forever, allowing to re-use the RAM for other purposes. Changing this value will clear the undo/redo stack.

**Disconnected arrow length**

The size of a disconnected node input arrow in pixels.

**Auto hide masks inputs**

When checked, any diconnected mask input of a node in the nodegraph will be visible only when the mouse is hovering the node or when it is selected.

**Merge node connect to A input**

If checked, upon creation of a new Merge node, the input A will be preferred for auto-connection and when disabling the node instead of the input B. This also applies to any other node with inputs named A and B.

Plug-ins
--------

**OpenFX plugins search path**

Extra search paths where Natron should scan for OpenFX plugins. Extra plugins search paths can also be specified using the OFX\_PLUGIN\_PATH environment variable. The priority order for system-wide plugins, from high to low, is: - plugins found in OFX\_PLUGIN\_PATH - plugins found in /usr/OFX/Plugins Plugins bundled with the binary distribution of Natron may have either higher or lower priority, depending on the "Prefer bundled plugins over system-wide plugins" setting. Any change will take effect on the next launch of Natron.

**PyPlugs search path**

Search path where Natron should scan for Python group scripts (PyPlugs). The search paths for groups can also be specified using the NATRON\_PLUGIN\_PATH environment variable.

**Use bundled plugins**

When checked, Natron also uses the plugins bundled with the binary distribution. When unchecked, only system-wide plugins are loaded (more information can be found in the help for the "Extra plugins search paths" setting).

**Prefer bundled plugins over system-wide plugins**

When checked, and if "Use bundled plugins" is also checked, plugins bundled with the Natron binary distribution will take precedence over system-wide plugins if they have the same internal ID.

Python
------

**After project created**

Callback called once a new project is created (this is never called when "After project loaded" is called.) The signature of the callback is : callback(app) where: - app: points to the current application instance

**Default after project loaded**

The default afterProjectLoad callback that will be set for new projects.

**Default before project save**

The default beforeProjectSave callback that will be set for new projects.

**Default before project close**

The default beforeProjectClose callback that will be set for new projects.

**Default after node created**

The default afterNodeCreated callback that will be set for new projects.

**Default before node removal**

The default beforeNodeRemoval callback that will be set for new projects.

**Load PyPlugs in projects from .py if possible**

When checked, if a project contains a PyPlug, it will try to first load the PyPlug from the .py file. If the version of the PyPlug has changed Natron will ask you whether you want to upgrade to the new version of the PyPlug in your project. If the .py file is not found, it will fallback to the same behavior as when this option is unchecked. When unchecked the PyPlug will load as a regular group with the informations embedded in the project file.

**Print auto-declared variables in the Script Editor**

When checked, Natron will print in the Script Editor all variables that are automatically declared, such as the app variable or node attributes.

Appearance
----------

**Font**

List of all fonts available on your system

**Stylesheet file (.qss)**

When pointing to a valid .qss file, the stylesheet of the application will be set according to this file instead of the default stylesheet. You can adapt the default stylesheet that can be found in your distribution of Natron.

Main Window
-----------

**Use black & white toolbutton icons**

When checked, the tools icons in the left toolbar are greyscale. Changing this takes effect upon the next launch of the application.

Curve Editor
------------

Dope Sheet
----------

Node Graph
----------

**Display plug-in icon on node-graph**

When checked, each node that has a plug-in icon will display it in the node-graph.Changing this option will not affect already existing nodes, unless a restart of Natron is made.

**Anti-Aliasing**

When checked, the node graph will be painted using anti-aliasing. Unchecking it may increase performances. Changing this requires a restart of Natron

**Default node color**

The default color used for newly created nodes.

**Default backdrop color**

The default color used for newly created backdrop nodes.

**Readers**

The color used for newly created Reader nodes.

**Writers**

The color used for newly created Writer nodes.

**Generators**

The color used for newly created Generator nodes.

**Color group**

The color used for newly created Color nodes.

**Filter group**

The color used for newly created Filter nodes.

**Transform group**

The color used for newly created Transform nodes.

**Time group**

The color used for newly created Time nodes.

**Draw group**

The color used for newly created Draw nodes.

**Keyer group**

The color used for newly created Keyer nodes.

**Channel group**

The color used for newly created Channel nodes.

**Merge group**

The color used for newly created Merge nodes.

**Views group**

The color used for newly created Views nodes.

**Deep group**

The color used for newly created Deep nodes.

Script Editor
-------------

**Font**

List of all fonts available on your system

**Font Size**

The font size
