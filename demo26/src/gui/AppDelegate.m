#import "AppDelegate.h"

@interface AppDelegate ()

@property (strong) IBOutlet NSTextFieldCell *label;

@end

@implementation AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    // Insert code here to initialize your application
}


- (void)applicationWillTerminate:(NSNotification *)aNotification {
    // Insert code here to tear down your application
}


- (BOOL)applicationSupportsSecureRestorableState:(NSApplication *)app {
    return YES;
}

// - cocoa 程序再最后一个窗口关闭后进程不退出, 下面是让它进程退出
- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication*) sender {
    return YES;
}

@end
