--- third_party/perfetto/src/base/unix_socket.cc.orig	2020-05-26 07:51:24 UTC
+++ third_party/perfetto/src/base/unix_socket.cc
@@ -37,7 +37,7 @@
 #include "perfetto/ext/base/string_utils.h"
 #include "perfetto/ext/base/utils.h"
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_MACOSX)
+#if PERFETTO_BUILDFLAG(PERFETTO_OS_MACOSX) || PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
 #include <sys/ucred.h>
 #endif
 
@@ -601,7 +601,7 @@ void UnixSocket::ReadPeerCredentials() {
   if (sock_raw_.family() != SockFamily::kUnix)
     return;
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) && !PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)) || \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
   struct ucred user_cred;
   socklen_t len = sizeof(user_cred);
