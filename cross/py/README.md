# 概述

package_from_installed.py 来源

https://chromium.googlesource.com/chromium/tools/depot_tools.git

在 win_toolchain 目录下

windows SDK 的默认版本是 10.0.26100.0

该脚本执行结果是 out.zip

# 我提取的SDK

 Visual Studio Community 2026
 Windows SDK 10.0.26100.0


# VisualStudioSetup.exe 参数

默认安装

```bat
VisualStudioSetup.exe^
    --channelUri https://aka.ms/vs/17/release/channel^
    --add Microsoft.VisualStudio.Workload.NativeDesktop^
    --add Microsoft.VisualStudio.Component.VC.ATLMFC^
    --add Microsoft.VisualStudio.Component.VC.Tools.ARM64^
    --add Microsoft.VisualStudio.Component.VC.MFC.ARM64^
    --includeRecommended --passive
```

## 选择更新通道

--channelUri <URI>

URI 的有效值
+ https://aka.ms/vs/stable/channel
  Visual Studio 2026 稳定版
+ https://aka.ms/vs/insiders/channel
  Visual Studio 2026 内部版
+ https://aka.ms/vs/17/release/channel
  Visual Studio 2022
+ https://aka.ms/vs/16/release/channel
  Visual Studio 2019
+ https://aka.ms/vs/15/release/channel
  Visual Studio 2017

https://learn.microsoft.com/zh-cn/visualstudio/install/command-line-parameter-examples?view=visualstudio#using---channeluri
