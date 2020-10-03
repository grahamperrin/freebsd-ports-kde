--- cmake/OpenCVGenPkgconfig.cmake.orig	2020-10-03 13:54:51 UTC
+++ cmake/OpenCVGenPkgconfig.cmake
@@ -45,7 +45,11 @@ if(NOT DEFINED CMAKE_HELPER_SCRIPT)
 if(INSTALL_TO_MANGLED_PATHS)
   ocv_update(OPENCV_PC_FILE_NAME "opencv-${OPENCV_VERSION}.pc")
 else()
-  ocv_update(OPENCV_PC_FILE_NAME opencv4.pc)
+  if (PORTS_OCV_PACKAGE)
+    ocv_update(OPENCV_PC_FILE_NAME "opencv4-${PORTS_OCV_PACKAGE}.pc")
+  else()
+    ocv_update(OPENCV_PC_FILE_NAME opencv4.pc)
+  endif()
 endif()
 
 # build the list of opencv libs and dependencies for all modules
