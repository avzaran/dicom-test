# DICOM Viewer Proof of Concept

This project is a simple proof-of-concept DICOM viewer based on Qt6, VTK and DCMTK. It demonstrates loading multiple series, synchronized navigation and basic measurement tools.

## Building

```
mkdir build
cd build
cmake .. -DCMAKE_PREFIX_PATH="<path to Qt>; <path to VTK>; <path to DCMTK>"
cmake --build .
```

Use Visual Studio or MinGW depending on your environment.

## Running

Run the `dicomviewer` executable. Use the `Load Series` menu to select a folder containing DICOM files. Open multiple series to view them side-by-side. Navigation (slice and zoom) is synchronized between viewers.

## Tests

```
cd build
ctest
```

## Future work

- Segmentation modules
- Registration tools
- PACS integration
- Advanced 3D rendering
