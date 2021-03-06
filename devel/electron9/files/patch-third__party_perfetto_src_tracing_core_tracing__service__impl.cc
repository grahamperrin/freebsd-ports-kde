--- third_party/perfetto/src/tracing/core/tracing_service_impl.cc.orig	2020-05-26 08:04:16 UTC
+++ third_party/perfetto/src/tracing/core/tracing_service_impl.cc
@@ -2326,6 +2326,7 @@ void TracingServiceImpl::SnapshotClocks(std::vector<Tr
 
 #if !PERFETTO_BUILDFLAG(PERFETTO_OS_MACOSX) && \
     !PERFETTO_BUILDFLAG(PERFETTO_OS_WIN) &&    \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD) && \
     !PERFETTO_BUILDFLAG(PERFETTO_OS_NACL)
   struct {
     clockid_t id;
