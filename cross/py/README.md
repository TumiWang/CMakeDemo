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
VisualStudioSetup.exe \
    --add Microsoft.VisualStudio.Workload.NativeDesktop \
    --add Microsoft.VisualStudio.Component.VC.ATLMFC \
    --add Microsoft.VisualStudio.Component.VC.Tools.ARM64 \
    --add Microsoft.VisualStudio.Component.VC.MFC.ARM64 \
    --includeRecommended --passive
```

## 选择更新通道

--channelId <ID>

ID 的有效值
+ VisualStudio.18.Stable
  Visual Studio 2026 
+ VisualStudio.17.Release
  Visual Studio 2022
+ VisualStudio.16.Release
  Visual Studio 2019
+ VisualStudio.15.Release
  Visual Studio 2017

## 选择更新的产品

例如：--productID Microsoft.VisualStudio.Product.Enterprise
就是 Visual Studio Enterprise
