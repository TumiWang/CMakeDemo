#import "AppDelegate.h"

#import <CoreFoundation/CoreFoundation.h>

@interface AppDelegate ()

@property (strong) IBOutlet NSTextFieldCell *label;

@end

@implementation AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    CFBundleRef br = CFBundleGetMainBundle();
    CFURLRef url = CFBundleCopyResourceURL(br, CFSTR("mycontent.txt"), NULL, NULL);

    if (!url) return;

    // text 就是 文件 mycontent.txt 中的内容
    // 这里指定的 mycontent.txt 使用的是UTF8
    NSString* text = [NSString stringWithContentsOfURL: (__bridge NSURL *)url encoding: NSUTF8StringEncoding error: NULL];

    CFRelease(url);

    // 设置文本框的内容
    [_label initTextCell: text];
}


- (void)applicationWillTerminate:(NSNotification *)aNotification {
    
}


- (BOOL)applicationSupportsSecureRestorableState:(NSApplication *)app {
    return YES;
}

// - cocoa 程序再最后一个窗口关闭后进程不退出, 下面是让它进程退出
- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication*) sender {
    return YES;
}

@end
