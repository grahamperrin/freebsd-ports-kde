--- samples/opengl/opengl_interop.cpp.orig	2019-04-04 21:22:40 UTC
+++ samples/opengl/opengl_interop.cpp
@@ -8,7 +8,7 @@
 #if defined(_WIN32)
 # define WIN32_LEAN_AND_MEAN
 # include <windows.h>
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 # include <X11/X.h>
 # include <X11/Xlib.h>
 #endif
@@ -59,7 +59,7 @@ class GLWinApp : public WinApp (public)
     virtual void cleanup() CV_OVERRIDE
     {
         m_shutdown = true;
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
         glXMakeCurrent(m_display, None, NULL);
         glXDestroyContext(m_display, m_glctx);
 #endif
@@ -112,7 +112,7 @@ class GLWinApp : public WinApp (public)
     }
 #endif
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
     int handle_event(XEvent& e) CV_OVERRIDE
     {
         switch(e.type)
@@ -172,7 +172,7 @@ class GLWinApp : public WinApp (public)
 
         m_hRC = wglCreateContext(m_hDC);
         wglMakeCurrent(m_hDC, m_hRC);
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
         m_glctx = glXCreateContext(m_display, m_visual_info, NULL, GL_TRUE);
         glXMakeCurrent(m_display, m_window, m_glctx);
 #endif
@@ -242,7 +242,7 @@ class GLWinApp : public WinApp (public)
 
             ::SelectObject(hDC, hOldFont);
         }
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 
         char buf[256+1];
         snprintf(buf, sizeof(buf)-1, "Time, msec: %2.1f, Mode: %s OpenGL %s, Device: %s", time, m_modeStr[mode].c_str(), use_buffer() ? "buffer" : "texture", oclDevName.c_str());
@@ -296,7 +296,7 @@ class GLWinApp : public WinApp (public)
                 texture.copyFrom(m, true);
             }
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
             XWindowAttributes window_attributes;
             XGetWindowAttributes(m_display, m_window, &window_attributes);
             glViewport(0, 0, window_attributes.width, window_attributes.height);
@@ -317,7 +317,7 @@ class GLWinApp : public WinApp (public)
 
 #if defined(_WIN32)
             SwapBuffers(m_hDC);
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
             glXSwapBuffers(m_display, m_window);
 #endif
 
@@ -431,7 +431,7 @@ class GLWinApp : public WinApp (public)
     }
 #endif
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
     KeySym keycode_to_keysym(unsigned keycode)
     {   // note that XKeycodeToKeysym() is considered deprecated
         int keysyms_per_keycode_return = 0;
@@ -456,7 +456,7 @@ class GLWinApp : public WinApp (public)
 #if defined(_WIN32)
     HDC                m_hDC;
     HGLRC              m_hRC;
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
     GLXContext         m_glctx;
 #endif
     cv::VideoCapture   m_cap;
@@ -509,7 +509,7 @@ int main(int argc, char** argv)
 
 #if defined(_WIN32)
     string wndname = "WGL Window";
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
     string wndname = "GLX Window";
 #endif
 
