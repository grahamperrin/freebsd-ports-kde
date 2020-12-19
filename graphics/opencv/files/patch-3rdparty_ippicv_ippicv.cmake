--- 3rdparty/ippicv/ippicv.cmake.orig	2019-04-05 06:00:26 UTC
+++ 3rdparty/ippicv/ippicv.cmake
@@ -50,7 +50,7 @@ function(download_ippicv root_var)
                STATUS res
                UNPACK RELATIVE_URL)
 
-  if(res)
+  if(1)
     set(${root_var} "${THE_ROOT}/${OPENCV_ICV_PACKAGE_SUBDIR}" PARENT_SCOPE)
   endif()
 endfunction()
