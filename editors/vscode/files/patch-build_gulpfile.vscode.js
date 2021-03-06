--- build/gulpfile.vscode.js.orig	2020-12-16 14:57:12 UTC
+++ build/gulpfile.vscode.js
@@ -267,7 +267,7 @@ function packageTask(platform, arch, sourceFolderName,
 		let result = all
 			.pipe(util.skipDirectories())
 			.pipe(util.fixWin32DirectoryPermissions())
-			.pipe(electron(_.extend({}, config, { platform, arch: arch === 'armhf' ? 'arm' : arch, ffmpegChromium: true })))
+			.pipe(electron(_.extend({}, config, { platform, arch: arch === 'armhf' ? 'arm' : arch, ffmpegChromium: false })))
 			.pipe(filter(['**', '!LICENSE', '!LICENSES.chromium.html', '!version'], { dot: true }));
 
 		if (platform === 'linux') {
