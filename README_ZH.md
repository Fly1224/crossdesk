<div align="center">
  <h1>OneDesk</h1>
  <p>轻量、跨平台的远程桌面，支持电脑、浏览器、移动端和终端连接，用桌面墙集中查看与操控多台设备。</p>
  <p><a href="#download">下载客户端</a> · <a href="#build">构建指南</a> · <a href="README.md">English</a></p>
</div>

<div align="center">

[![Platforms](https://img.shields.io/badge/platform-Windows%20%7C%20macOS%20%7C%20Linux%20%7C%20iOS%20%7C%20Android%20%7C%20HarmonyOS-blue?style=flat)](#download)

[![Clients](https://img.shields.io/badge/client-Desktop%20%7C%20Mobile%20%7C%20Web%20%7C%20CLI-2ea44f?style=flat)](#download)

[![Build](https://img.shields.io/github/actions/workflow/status/Fly1224/crossdesk/build.yml?style=flat&label=build)](https://github.com/Fly1224/crossdesk/actions/workflows/build.yml)
[![License: GPL v3](https://img.shields.io/badge/license-GPL--3.0-blue?style=flat)](LICENSE)

</div>

## 项目简介

OneDesk 基于开源远程桌面项目 [CrossDesk](https://github.com/kunkundi/crossdesk)（GPL-3.0）定制。它让你从电脑、浏览器、手机或终端连接远端电脑，也能通过桌面墙集中查看与操控多台设备。项目基于 [MiniRTC](https://github.com/kunkundi/minirtc)，支持使用自建的信令与 TURN 服务自托管。

[主要功能](#features) · [下载与平台支持](#download) · [构建指南](#build) · [快速连接](#quick-start) · [终端 CLI](#cli) · [Agent / MCP](#mcp) · [IP 直连](#lan-direct) · [可信设备](#trusted-devices) · [会话与设置](#session) · [使用指南](docs/USER_GUIDE.md) · [自托管](#self-hosting) · [文档与反馈](#development)

<a id="features"></a>

## 主要功能

- **跨平台远控：** Windows、macOS、Linux 桌面互控，浏览器及原生 iOS / Android 客户端访问电脑；鸿蒙 PC 与移动端处于开发阶段。
- **局域网 IP 直连：** 桌面客户端和 Android、iOS、鸿蒙移动端可通过 IP、端口和六位密码连接电脑，无需云端信令服务；支持独立端口、记住密码及按模式显示近期设备。
- **终端主控：** 在终端中通过设备 ID 观看和操控远程桌面，支持 ANSI / Kitty / Sixel 画面、局部缩放与平移、持续本地命令模式及 Pi 扩展，可单独构建。
- **桌面墙：** 多设备实时预览、分组、放大操控、群控和批量文件分发。
- **画面与声音：** H.264 / AV1、硬件编解码、远端音频，会话内调整画质、帧率和远端显示器分辨率；记住已确认的分辨率选择，最后一个控制端断开后恢复原显示模式。可用能力随平台与设备而异。
- **日常协作：** 多显示器切换、键鼠与组合键、文本剪贴板；双栏文件浏览支持目录导航、文件与文件夹双向传输、拖放和任务管理。
- **Agent / MCP：** 通过本机 MCP 服务授权 Agent 观察和操作远端电脑，提供实时监看、人工接管、多会话、剪贴板和文件工具。
- **可信设备：** 桌面端可选开启可信设备限制，在连接密码之外校验设备身份；支持复制、粘贴配对信息，提前添加允许访问本机的设备。
- **部署与运维：** P2P 直连、TURN 中继、SRTP 媒体加密、自托管，以及 Windows 登录前远控和 Linux 无头运行。

<a id="download"></a>

## 下载与平台支持

每次推送后 CI 流水线都会产出全平台安装包，可在 [Actions](https://github.com/Fly1224/crossdesk/actions/workflows/build.yml) 最近一次成功运行的 **Artifacts** 区下载；发布版本 tag 后也可从 [Releases](https://github.com/Fly1224/crossdesk/releases) 获取。

| 平台 | 支持范围与安装要求 |
| --- | --- |
| Windows | **控制 / 被控**；Windows 10+，x64；`onedesk-win-x64-…exe` 安装包，另提供 `onedesk-win-x64-portable-…zip` 便携版 |
| macOS | **控制 / 被控**；macOS 14.0+；按 Intel / Apple Silicon 选择 x64 / arm64 `onedesk-macos-…pkg`；构建为未签名版本，首次打开需在 Gatekeeper 中放行 |
| Linux | **控制 / 被控**；Ubuntu 20.04+、glibc 2.31 基线；amd64 / arm64 `onedesk-linux-…deb` |
| iOS / iPadOS | **仅控制**；当前源码目标为 iOS 16.0+，需自行构建签名，见 [iOS 构建说明](apps/ios/README.md) |
| Android | **仅控制**；Android 8.0+，arm64；debug APK 可直接安装，release APK 需自行签名 |
| 鸿蒙 PC（开发版） | **控制 / 被控**；API 26，arm64；使用 DevEco 构建并签名 HAP，仍在进行真机验收 |
| 鸿蒙手机 / 平板（开发版） | **仅控制**；API 20+，arm64；使用 DevEco 构建并签名 HAP，仍在进行真机验收 |
| 终端 CLI（开发版） | **仅控制**；分发目标为 macOS / Linux（x64、arm64）和 Windows（x64）；从源码构建，见 [CLI 说明](apps/cli/README.md) |
| MCP（开发版） | **仅控制**；在 Codex 或 DSH 中操作远端并监看画面，见 [安装与使用](apps/mcp/README.md) |

- **Linux：** 已有桌面选普通版 `onedesk-linux-…deb`；需要独立 Xfce 桌面的服务器选 `onedesk-virtual-desktop-xfce-…deb`。两者选择其一，安装与启动方法见 [使用指南](docs/USER_GUIDE.md#installation) 和 [无头运行](docs/HEADLESS.md)。
- **macOS：** 首次运行时按提示授予屏幕录制及辅助功能权限；前者用于桌面采集，后者用于远程键鼠输入。[权限说明](docs/USER_GUIDE.md#installation)
- **iOS：** 未签名产物需使用自己的证书签名，步骤见 [iOS 构建说明](apps/ios/README.md)。鸿蒙需使用 DevEco 构建并签名，见 [鸿蒙说明](apps/harmony/README.md)。

<a id="build"></a>

## 构建指南

桌面客户端使用 Xmake 构建。准备 Git、Xmake 3.1.1 或更新版本，并按对应平台安装编译工具链与依赖，然后获取源码及子模块：

```bash
git clone --recurse-submodules https://github.com/Fly1224/crossdesk.git
cd crossdesk
```

CI 流水线在每次推送时构建全部平台（Windows x64 安装包与便携版、macOS x64 / arm64 pkg、Linux amd64 / arm64 deb、iOS 与 Android），因此 `.github/workflows/build.yml` 也可以作为完整构建的可执行参考。

- **桌面客户端：** 按 [Windows](docs/BUILD.md#windows)、[macOS](docs/BUILD.md#macos) 或 [Linux](docs/BUILD.md#linux) 的步骤配置、编译和运行；打包、签名与 CI 配置见 [完整构建指南](docs/BUILD.md)。
- **移动端与鸿蒙：** [iOS / iPadOS](apps/ios/README.md)、[Android](apps/android/README.md)、[鸿蒙手机 / 平板](apps/harmony/README.md)、[鸿蒙 PC](apps/harmony/desktop-port/README.md)。
- **终端与集成：** [CLI 构建与运行](apps/cli/README.md)、[MCP 构建与集成](apps/mcp/DEVELOPMENT.md)。

<a id="quick-start"></a>

## 快速连接

### 通过设备 ID 连接

1. **准备被控电脑。** 安装并运行 OneDesk，切换至 ID 连接模式，等待显示“已连接服务器”，查看“本桌面”中的本机 ID 和密码。
2. **发起连接。** 在另一台电脑的 OneDesk 中输入被控电脑的 9 位 ID，点击“连接”；也可使用原生移动端。
3. **验证密码。** 输入被控电脑当前的连接密码，等待远程画面出现。桌面端可勾选“记住密码”，后续从“近期连接”重连。

使用自建服务器时，两端需要接入同一服务；升级客户端前请先更新服务端。更多连接和密码操作见 [使用指南](docs/USER_GUIDE.md#quick-start)，连接失败、黑屏或无法操作键鼠时见 [常见问题](docs/FAQ.md)。

<a id="lan-direct"></a>

### 通过局域网 IP 直连

手机或平板可在首页的 **设备 ID 或 IP 地址** 中粘贴被控电脑显示的地址，再输入电脑的 **IP 直连密码**。桌面端操作如下。

1. **切换模式。** 使用桌面客户端时，点击左上角模式按钮切换到 **IP 直连模式**。若按钮未显示，在 **设置 → 常规 → 网络连接** 中勾选 **启用 IP 直连** 并保存。
2. **填写地址。** 在控制端输入被控电脑显示的 `IP:端口`，例如 `192.168.1.20:52888` 或 `[2001:db8::20]:52888`，点击“连接”。只输入 IP 时使用默认端口 **52888**；请以对方界面显示的实际端口为准。
3. **输入密码。** 输入被控电脑在 IP 直连模式下显示的 **6 位英文字母或数字密码**，可勾选“记住密码”。切换模式时，“近期连接”同步切换为对应模式的设备记录。

控制端和被控电脑需要在局域网或 VPN 内可互相访问；网络可以有外网，也可以没有外网，直连会话不依赖云端信令服务。主窗口可直接切换本机 IP、修改端口和密码，默认开启所有 IP 接口监听，支持 IPv4 和 IPv6，支持通过 VPN 等接口连接，可在设置的“网络连接”中调整；关闭设置中的“启用 IP 直连”会停止监听、断开 IP 直连会话并隐藏模式按钮。详见 [IP 直连使用指南](docs/USER_GUIDE.md#lan-direct)。

<a id="trusted-devices"></a>

### 仅允许可信设备连接（可选）

桌面端的可信设备限制**默认关闭**，适用于 ID 连接和 IP 直连。开启后，控制端仍需通过原有密码验证，并持有可信名单中设备的配对私钥；仅知道 ID 和密码不能通过这项限制。

1. **在控制端复制配对信息。** 打开 **设置 → 常规 → 隐私保护 → 管理可信设备**，在 **本机配对信息** 中点击 **复制配对信息**。
2. **在被控端添加控制端。** 打开同一管理界面，将收到的信息粘贴到 **添加可信设备** 输入框，点击 **添加** 即可加入，无需再次确认，也无需先建立远程连接。
3. **在被控端开启限制。** 返回设置，勾选 **仅允许可信设备控制** 并保存。之后照常通过 ID 或 IP 发起连接、验证密码。

配对信息只包含公钥、设备名称和 ID，不含私钥或密码，应通过可信渠道传递。添加后可点击 **查看指纹** 与控制端核对；也允许添加本机，同一公钥不会重复加入。信任是单向的，如需互相控制，应在双方分别添加对方。

添加和移除会立即保存；开启限制时，**移除信任** 会断开对应设备的会话，名单为空则拒绝所有控制端。也可以从管理界面的已连接设备中添加完成身份验证的控制端。

**兼容范围：** 使用支持配对的新版桌面端、iOS、Android 或鸿蒙移动端。手机和平板从“设置 → 本机配对信息”复制配对信息，再添加到被控电脑。旧客户端和当前终端 CLI 无法连接开启此限制的被控端。

重装、清除应用数据或迁移电脑前，请先查看 [身份备份与迁移](docs/CONNECTIONS.md#backup)。仅保存 ID 和密码不足以恢复已绑定的桌面身份；更换设备身份后需要重新配对。

<a id="session"></a>
<a id="settings"></a>

## 会话操作与设置

远程会话支持显示器切换、画质与帧率调整、声音、文本剪贴板同步和双向文件传输。工具栏还可查看网络状态、控制隐私屏；桌面设置中可配置 IP 直连开关、可信设备限制、编码、中继、自托管、最小化时暂停视频及桌面墙画面预算。

被控端为 Windows、macOS 或 Linux X11 时，可在 **画面设置 → 分辨率** 中选择当前显示器支持的模式，无需重连。桌面和原生移动端会记住远端确认成功的选择，重连时在仍受支持的情况下重新应用；最后一个控制端断开后，被控端恢复本轮连接首次调整前的显示模式。Linux 需要 X11 采集和 RandR，Wayland / XWayland 暂不支持此项调整。

- [会话操作](docs/USER_GUIDE.md#session)：工具栏、文本剪贴板、文件保存和隐私屏。
- [客户端设置与更新](docs/USER_GUIDE.md#settings)：常规设置、桌面墙传输及版本检查。
- [桌面墙使用说明](docs/deskhub.md)：整理设备、群控、批量传文件及降低带宽占用。

<a id="cli"></a>

## 终端客户端 CLI

终端客户端（内部名 `crossdesk-cli`）在终端中通过 9 位设备 ID 连接被控电脑，默认只读、静音。普通终端使用 ANSI 字符画面，支持 Kitty 或 Sixel 图形协议的终端可显示像素画面；可切换显示器、调整画质、放大细节和平移，也可明确开启键鼠控制。CLI 可以独立于桌面 GUI 构建，被控电脑仍需运行 OneDesk 并提供可捕获的图形会话，信令服务需支持 `cli` 临时身份注册。

默认只读、静音。只读模式下按 `c` 开启键鼠控制，按 `+/-` 或滚轮缩放，按 `f` 回到全景。**控制模式下退出时，先按 `Ctrl+]`，再按 `q`**，否则普通按键会发给远端电脑。

CLI 通过设备 ID 连接，暂不提供 IP 直连、音频播放、文件传输或剪贴板同步，也不支持连接开启可信设备限制的电脑。被控电脑需要运行 OneDesk 并有可用的桌面。自托管用户需要使用支持 CLI 连接的服务端。

[CLI 构建与运行](apps/cli/README.md) · [选项、Pi 扩展与源码构建](apps/cli/docs/terminal-client.md) · [npm 分发说明](apps/cli/docs/npm-distribution.md)

<a id="mcp"></a>

## Agent 与 MCP

内置 MCP 服务让你在 Codex 或 DeepSeek Harness 对话中下发远端任务，并在侧边实时查看远端画面。在远端电脑运行 OneDesk，按下方对应应用的安装指引配置后，在面板中选择设备并授权即可。

| 宿主 | 安装与配置 | 远端画面 |
| --- | --- | --- |
| Codex 桌面版 | [Codex 配置](apps/mcp/README.md#install-codex)：注册 MCP 服务，无需额外插件 | Agent 打开右侧内置浏览器 |
| DeepSeek Harness 桌面版（DSH） | [DSH 配置](apps/mcp/README.md#install-dsh)：安装一个平台插件包，MCP 自动注册 | 插件自动打开当前会话的浏览器侧栏 |

1. [下载本机平台包](apps/mcp/README.md#install-package)，按上表对应指引配置。
2. 让 Agent 打开 OneDesk，在本地监看面板选择设备并输入密码，授予只读或控制权限；保存密码与允许自动连接是两个独立选项。
3. Agent 通过截图、键鼠操作和结构化桌面工具完成任务；你可以实时监看、暂停 Agent、人工接管或断开连接。

服务支持最多 8 个并发设备会话、多显示器监看、远端文本剪贴板、文件浏览与传输、音频、锁定系统，以及本机输入密码解锁。窗口与无障碍操作取决于远端平台和权限，部分工具需要较新的被控端。浏览器、终端与 MCP Apps 面板的被控端要求不同，配置与兼容性见 [MCP 说明](apps/mcp/README.md)。

<a id="mobile"></a>

## 移动端与鸿蒙

<a id="ios"></a>

### iOS / iPadOS

从源码构建并签名原生控制端（见 [iOS 构建说明](apps/ios/README.md)）。支持触控与虚拟鼠标、多显示器、远端音频、文件传输和文本剪贴板。点按悬浮菜单中的 **剪贴板** 可发送本机文本，单次最多 128 KiB。画面设置可切换受支持的远端分辨率并记住确认的选择。iPhone 和 iPad 暂不支持作为被控端。

[使用指南](docs/USER_GUIDE.md#ios) · [构建与签名](apps/ios/README.md)

<a id="android"></a>

### Android

原生控制端支持触控、外接键鼠、显示器切换、文件传输、文本剪贴板和画面设置。切换应用时优先使用画中画，亦提供后台通知兜底；可通过悬浮菜单控制电脑隐私屏。Android 手机和平板暂不支持作为被控端。

[使用指南](docs/USER_GUIDE.md#android) · [源码构建](apps/android/README.md)

<a id="harmonyos"></a>

### 鸿蒙（开发版）

PC 客户端同时作为控制端和被控端，与桌面 UI 和桌面墙共用。手机和平板使用原生 ArkUI 控制端，支持触控、外接输入设备、显示器、文本剪贴板和文件传输。PC 采集画面与控制输入需要系统授权。真机与长会话验收仍在进行。

[使用与限制](docs/USER_GUIDE.md#harmonyos) · [构建与签名](apps/harmony/README.md) · [PC 端说明](apps/harmony/desktop-port/README.md) · [移动端特性](apps/harmony/MOBILE_PARITY.md)

<a id="windows-service"></a>

## 无人值守与无头运行

- **Windows：** OneDesk Service 支持锁屏、登录界面与安全桌面。已安装的 Release 版开启 **开机自启** 后，登录前后使用相同的设备 ID 和密码；登录后界面自动打开，远程连接保持不中断。便携版与 Debug 版不提供该开关。无显示器时，被控端会尝试准备虚拟显示器并恢复此前记录的分辨率。能力、限制与命令见 [Windows 无人值守指南](docs/USER_GUIDE.md#windows-service)。
- **Linux：** 复用已有桌面，或创建独立的 Xvfb / Xfce 会话，见 [Linux 无头运行](docs/HEADLESS.md)。

<a id="self-hosting"></a>

## 自托管

自建信令与 TURN 服务后，在 **设置 → 常规 → 自托管配置** 中启用；控制端和被控端需要接入同一服务。

[部署指南](docs/SELF_HOSTING.md) · [客户端配置](docs/USER_GUIDE.md#self-hosting) · [服务端源码](https://github.com/kunkundi/crossdesk-server) · [Web 客户端部署](https://github.com/kunkundi/crossdesk-web-client)

<a id="development"></a>

## 文档与反馈

- [文档导航](docs/README.md)：按任务查找帮助。
- [使用指南](docs/USER_GUIDE.md)：安装、连接、会话操作、设置与无人值守。
- [常见问题](docs/FAQ.md)：连接失败、黑屏、权限与文件保存。
- [连接方式与可信设备](docs/CONNECTIONS.md)：连接模式、配对与身份迁移。
- [客户端更新](docs/UPDATER.md)：检查更新、安装更新与更新失败恢复。
- [源码构建](docs/BUILD.md)：依赖、编译、打包与签名。
- [架构与集成](docs/README.md#构建与集成)：GUI 与连接架构、CLI / MCP 接口及平台支持。
- [版本与发布](docs/VERSIONING.md)：组件版本同步、发布编号与更新清单。

从桌面主菜单打开 **反馈与建议** 即可导出诊断日志并[提交 Issue](https://github.com/Fly1224/crossdesk/issues)。请附上双方操作系统、客户端版本、连接模式、错误信息和复现步骤；分享前请检查日志和截图中是否有隐私信息。详见 [反馈与诊断日志](docs/USER_GUIDE.md#feedback)。

## 许可与致谢

本项目基于 JUNKUN DI 开发的 [CrossDesk](https://github.com/kunkundi/crossdesk) 定制，底层依赖 [MiniRTC](https://github.com/kunkundi/minirtc)。感谢上游作者与社区对原始项目的贡献。

Copyright (c) 2026 JUNKUN DI.

OneDesk 依据 [GPL-3.0-only](LICENSE) 许可发布。参见[隐私政策](PRIVACY.md)。

> AI生成
