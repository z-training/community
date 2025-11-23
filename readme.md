# Zephyr Training Community Edition — Lab Materials

Welcome to the ZTraining Community Edition labs!
This repository contains hands-on training material designed to help developers
learn and practice embedded development using Zephyr RTOS.

Inside this repo, you’ll find:
- Guided lab exercises
- Starter and solution projects
- Code templates and examples
- Supporting documentation

------------------------------------------------
Adding to a West Workspace
------------------------------------------------

To include this repository in your Zephyr workspace, add the following entry
to your west manifest (west.yml):
```
    projects:
      - name: ztraininglabs
        url: https://github.com/z-training/community
        revision: main
        path: ZTrainingLabs
```

Then update your workspace:

    `$ west update`

This will clone the repo into:

    `<workspace_root>/ZTrainingLabs/`

