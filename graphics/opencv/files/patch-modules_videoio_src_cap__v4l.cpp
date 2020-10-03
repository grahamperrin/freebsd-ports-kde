--- modules/videoio/src/cap_v4l.cpp.orig	2020-10-03 09:49:39 UTC
+++ modules/videoio/src/cap_v4l.cpp
@@ -231,7 +231,9 @@ make & enjoy!
 #include <poll.h>
 
 #ifdef HAVE_CAMV4L2
+#ifndef __FreeBSD__
 #include <asm/types.h>          /* for videodev2.h */
+#endif
 #include <linux/videodev2.h>
 #endif
 
