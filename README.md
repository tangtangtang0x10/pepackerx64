# PE Packer x64 - 64位版本

这是PE Packer的x64版本，仅支持64位PE文件的加壳和混淆。
参考项目https://github.com/notcpuid/pe-packer 将其转换为支持x64 修改一些版本适配问题 切勿用于违法途径 仅供研究
定期跟新新技术，觉得不错请给我点个Star，别j8来问我能不能过360！！！

## 主要改动

### 架构支持
- **仅支持x64**: 从原版的x86改为x64架构
- 所有寄存器从32位改为64位 (eax→rax, ebx→rbx等)
- PE类型检查从 `pe_type_32` 改为 `pe_type_64`
- 图像基址从 `get_image_base_32()` 改为 `get_image_base_64()`

### 核心技术

#### 1. 代码混淆
- **MBA (Mixed Boolean Arithmetic)**: 混合布尔算术混淆
- **Anti-Disassembly**: 反反汇编技术
- **Junk Code**: 垃圾代码插入
- **Control Flow Obfuscation**: 控制流混淆

#### 2. 加密技术
- **函数级加密**: 使用XOR加密指定地址范围的函数
- **节区加密**: 加密PE文件的特定节区（如.reloc）
- **运行时解密**: 生成解密桩代码

#### 3. 功能特性
- `-oep_call`: 入口点调用混淆
- `-adasm`: 反反汇编
- `-mba`: 混合布尔算术
- `-senc`: 节区加密
- `-fpack addr1 addr2`: 函数范围加密
- `-finstr`: 伪造无效指令
- `-noaslr`: 禁用ASLR

## 项目结构

```
pe-packer-x64/
├── pe-packer-x64/
│   ├── core/           # 核心加壳逻辑
│   │   ├── core.cpp    # 主要加壳流程
│   │   ├── mba.cpp     # MBA混淆
│   │   └── adasm.cpp   # 反反汇编
│   ├── gui/            # GUI界面
│   ├── handler/        # 工具函数
│   ├── utils/          # 工具类
│   ├── asmjit/         # AsmJit库 (需要添加)
│   ├── pe_lib/         # PE Bliss库 (需要添加)
│   └── pe-packer-x64.cpp  # 主入口
├── vendor/
│   └── imgui/          # ImGui库 (需要添加)
└── pe-packer-x64.sln   # VS2019解决方案
```

## 依赖库

在编译之前，需要添加以下依赖库：

### 1. AsmJit
```bash
git clone https://github.com/asmjit/asmjit.git pe-packer-x64/pe-packer-x64/asmjit
```

### 2. PeBliss
```bash
# 下载 PeBliss 库并放置到 pe-packer-x64/pe-packer-x64/pe_lib/
```

### 3. Dear ImGui
```bash
git clone https://github.com/ocornut/imgui.git pe-packer-x64/vendor/imgui
```

## 编译说明

1. **安装Visual Studio 2019**
   - 确保安装了C++桌面开发工作负载
   - Windows 10 SDK

2. **添加依赖库**
   - 按照上述依赖库说明添加所需库文件

3. **打开解决方案**
   ```
   pe-packer-x64.sln
   ```

4. **选择配置**
   - Debug|x64 或 Release|x64

5. **编译**
   - Ctrl+Shift+B 或 菜单: 生成 → 生成解决方案

## 使用方法

### GUI模式
直接运行程序即可进入图形界面。

### 命令行模式
```bash
pe-packer-x64.exe <input.exe> <output.exe> <mutations> [flags...]

# 示例
pe-packer-x64.exe file.exe file_packed.exe 5 -mba -senc -fpack 0x140001040 0x140001072
```

### 参数说明
- `input.exe`: 输入的PE文件（必须是x64）
- `output.exe`: 输出的加壳文件
- `mutations`: 变异次数（实际次数 = 该值 × 10）
- `flags`: 混淆选项

## 注意事项

1. **仅支持x64**: 不支持x86/32位程序
2. **不支持.NET**: CLR程序不支持
3. **ASLR限制**: OEP混淆需要禁用ASLR
4. **测试环境**: 在使用前请在测试环境中验证

## 技术细节

### x86到x64的主要修改

#### 寄存器替换
```cpp
// x86 → x64
eax → rax
ebx → rbx
ecx → rcx
edx → rdx
esi → rsi
edi → rdi
esp → rsp
ebp → rbp
```

#### 数据类型
```cpp
// 地址从32位改为64位
uint32_t → uint64_t (用于地址)
std::stoul → std::stoull (地址解析)
```

#### PE操作
```cpp
// PE类型检查
pe_type_32 → pe_type_64

// 图像基址
get_image_base_32() → get_image_base_64()
```

## 开发计划

- [ ] Anti-Debug 技术
- [ ] Anti-VM 检测
- [ ] IAT混淆
- [ ] .MAP文件解析支持
- [ ] 更多混淆技术

## 许可证

参考原始项目的LICENSE.txt文件。

## 贡献

这是原始PE Packer项目的x64改进版本。
原始项目: [pe-packer](https://github.com/notcpuid/pe-packer)
