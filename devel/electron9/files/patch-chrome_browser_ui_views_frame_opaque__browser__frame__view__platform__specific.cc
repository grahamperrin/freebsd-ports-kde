--- chrome/browser/ui/views/frame/opaque_browser_frame_view_platform_specific.cc.orig	2020-05-26 07:48:17 UTC
+++ chrome/browser/ui/views/frame/opaque_browser_frame_view_platform_specific.cc
@@ -6,7 +6,7 @@
 
 #include "build/build_config.h"
 
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_FREEBSD)
 
 // static
 std::unique_ptr<OpaqueBrowserFrameViewPlatformSpecific>
