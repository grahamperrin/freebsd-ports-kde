--- third_party/blink/renderer/platform/wtf/stack_util.cc.orig	2020-05-26 07:48:38 UTC
+++ third_party/blink/renderer/platform/wtf/stack_util.cc
@@ -17,6 +17,11 @@
 extern "C" void* __libc_stack_end;  // NOLINT
 #endif
 
+#if defined(OS_FREEBSD)
+#include <sys/signal.h>
+#include <pthread_np.h>
+#endif
+
 namespace WTF {
 
 size_t GetUnderestimatedStackSize() {
