--- samples/opengl/winapp.hpp.orig	2019-04-04 21:14:55 UTC
+++ samples/opengl/winapp.hpp
@@ -1,7 +1,7 @@
 #if defined(_WIN32)
 # define WIN32_LEAN_AND_MEAN
 # include <windows.h>
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 # include <X11/X.h>
 # include <X11/Xlib.h>
 # include <X11/Xutil.h>
@@ -12,7 +12,7 @@
 #include <GL/gl.h>
 #if defined(_WIN32)
 # include <GL/glu.h>
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 # include <GL/glx.h>
 #endif
 
@@ -77,7 +77,7 @@ class WinApp (public)
         ::ShowWindow(m_hWnd, SW_SHOW);
         ::UpdateWindow(m_hWnd);
         ::SetFocus(m_hWnd);
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
         m_display = XOpenDisplay(NULL);
 
         if (m_display == NULL)
@@ -120,7 +120,7 @@ class WinApp (public)
     {
 #if defined(_WIN32)
         ::DestroyWindow(m_hWnd);
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
         XDestroyWindow(m_display, m_window);
         XCloseDisplay(m_display);
 #endif
@@ -151,7 +151,7 @@ class WinApp (public)
         }
 
         return static_cast<int>(msg.wParam);
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
         m_end_loop = false;
 
         do {
@@ -195,7 +195,7 @@ class WinApp (public)
     }
 #endif
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
     virtual int handle_event(XEvent& e) = 0;
 #endif
 
@@ -207,7 +207,7 @@ class WinApp (public)
 #if defined(_WIN32)
     HINSTANCE     m_hInstance;
     HWND          m_hWnd;
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
     Display*      m_display;
     XVisualInfo*  m_visual_info;
     Window        m_window;
