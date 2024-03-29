## 计算机系统概述
### **阐述冯诺依曼结构，冯诺依曼结构五大部件是什么？目前哪个最有发展空间？**
* 冯诺依曼五大部件是运算器、控制器、存储器、输入设备和输出设备。
* 运算器更有发展空间，决定着计算机性能的优劣。

### **计算机为什么要发展多核处理器？**
* 衡量处理器性能的主要指标是每个时钟周期内可以执行的指令数(IPC: Instruction Per Clock)和处理器的主频。CPU的主频就是每秒钟做周期性变化的次数，1秒钟只有1次时钟周期的改变叫1Hz。主频为1GHz就是1秒中有10亿个时钟周期。
* 因此，提高处理器性能就是通过两个途径：提高主频和提高IPC。处理器微架构的变化可以提高IPC，效率更高的微架构可以提高IPC，从而提高处理器的性能。但是对于同一代的架构，改良架构来提高IPC的幅度是非常有限的，所以在单核处理器时代通过提高处理器的主频来提高性能就成了唯一的手段。
* 但是提高主频会导致处理器的功耗以指数性上升，功耗上升会导致温度上升，很快会撞频率墙。
* 所以，业界普遍采取的做法是通过提高指令执行的并行度来提高IPC，而提高并行度有两种途径，一是提高处理器微架构的并行度，二是采用多核架构。
* 多核处理器相比相同性能的单核处理器，多核处理器的主频可以更低，从而很好的控制了功耗。
* 未来处理器发展的趋势是：为了达到更高的性能，在采用相同微架构的情况下，可以增加处理器的内核数量同时维持较低的主频。

### **计算机的主要性能指标？**
* 机器字长：机器字长是指计算机进行一次整数运算所能处理的二进制数据的位数，通常与CPU的寄存器位数、加法器有关。因此，机器字长一般等于内部寄存器的大小，字长越长，数的表示范围越大，计算精度越高。计算机字长通常选定为字节(8bit)的整数倍。
* 数据通路带宽：数据通路带宽是指数据总线一次所能并行传送信息的位数。
* 主存容量：主存容量是指主存储器所能存储信息的最大容量，通常以字节来衡量。
* 运算速度：
    + 吞吐量和响应时间：
        - 吞吐量：指系统在单位时间内处理请求的数量。它取决于信息能多快地输入内存，CPU能多快地取指令，数据能多快地从内存取出或存入，以及所得结果能多快地从内存送给一台外部设备。因此系统吞吐量主要取决于主存地存取周期；
        - 响应时间：指从用户向计算机发送一个请求，到系统对该请求做出响应并获得所需结果的等待时间。通常包括CPU时间（运行一个程序所花费的时间）与等待时间（用于磁盘访问、存储器访问、I/O操作、操作系统开销等的时间）
    + 主频和CPU时钟周期：
        - 主频：机器内部时钟的频率；
        - CPU时钟周期：通常为节拍脉冲，即主频的倒数，它是CPU中最小的时间单位，每个动作至少需要1个时钟周期；
    + CPI(Clock cycle Per Instruction)，即执行一条指令所需的时钟周期数。

### **为什么Linux的程序无法在Windows下运行？**
* 二者的可执行代码格式的一样，Linux的可执行代码文件格式是ELF(Execuatable and Linkable File Format)，Windows的可执行代码文件格式是PE(Portable Executable Format).
* Windows下提供了WSL(Windows Subsystem for Linux)可以解析和加载ELF格式的文件，Linux下提供了开源项目Wine兼容PE格式的装载器。
* 衍生问题: Linux通过Wine是否就能够完美的运行Windows程序？
    + 不能，大部分的程序往往依赖操作系统提供的动态链接库，系统调用等等，在Linux在这些往往都没法对等实现。

## 数据的表示和运算
### **单精度浮点数和多精度浮点数的区别？你什么时候选单精度，什么时候选双精度？**
* 单精度浮点数占据32位二进制，1位为符号位，0代表正数，1代表负数，8位指数位，尾数23位；双精度浮点数占据64位二进制，1位为符号位，11位为指数位，52为尾数位；
* 区别：
    + 所占内存不同：单精度浮点数占用4个字节（32位）存储空间来存储一个浮点数；双精度浮点数使用8个字节（64位）；
    + 所存的数值范围不同：单精度浮点数的数值范围为-3.4E38～3.4E38，而双精度浮点数可以表示的数字的绝对值范围大约是：-2.23E308 ~ 1.79E308；
    + 十进制下的位数不同：单精度浮点数最多有7位十进制有效数字，如果某个数的有效数字位数超过7位，当把它定义为单精度变量时，超出的部分会自动四舍五入。双精度浮点数可以表示十进制的15或16位有效数字，超出的部分也会自动四舍五入。

### **在计算机中，为什么要采用二进制来表示数据？**
* 从**可行性**来说，采用二进制，只有0和1两个状态，能够表示0、1两种状态的电子器件很多，如开关的接通和断开、晶体管的导通和截止、磁元件的正负剩磁、电位电平的高与低等，都可表示0、1两个数码。使用二进制，电子器件具有实现的可行性；
* 从**运算的简易性**来说，二进制数的运算法则少，运算简单，使计算机的硬件结构大大简化（十进制的乘法口诀表有55条公式，而二进制乘法只有4条规则）；
* 从**逻辑上**来说，由于二进制0和1正好和逻辑代数的假(false)和(true)相对应，使用二进制表示二值逻辑更自然。

### **什么是上溢和下溢？**
* 上溢：两个正数相加，结果为负（即：大于机器所能表示的最大正数）
* 下溢：两个负数相加，结果为正（即：大于机器所能表示的最小负数）

### **计算机如何实现乘除（实现二进制乘除法）**
* 乘法计算机制：依次以被乘数的低位到高位计算。若第n位不为0，那么乘数就左移n位。若第n位等于0，那么这步运算结果记为0，最后结果相加；二进制单位逐位计算可以通过与门(and gate)实现。
* 除法计算机制：除数从高位到低位的数字依次和被除数进行比较，如果大于等于被除数，则结果为1，并得余数。如果小于被除数则将上一步得余数左移一位并加上上一位的数字进行比较，依次类推，最终依次将计算结果相连组成二进制就是商。
* ALU中的运算机制：
    + 加法->加法。
    + 减法->取反，加法。
    + 乘法->移位，逻辑判断，累加
    + 除法->移位，逻辑判断，累减（本质上是加法）

## 存储系统

### **阐述多级存储系统**
* ![avatar](picture/%E5%AD%98%E5%82%A8%E5%8C%BA%E5%88%92%E5%88%86.png)
* 存储器的层次结构主要体现在两个存储层次上，即Cache-主存和主存-辅存。
    + Cache-主存层次主要对CPU的访存速度起增加作用，从整体运行效果分析，CPU访存速度加快，接近于Cache速度，而寻址空间与位价却接近于主存。
    + 主存-辅存层次在存储系统中主要起到扩容作用，从程序员的角度来看，其所使用的存储器其容量和位价接近于辅存，而速度接近于主存。
    + 两个存储层次，从整个存储系统来看，起到了速度快、容量大、位价低的优化效果。主存-Cache之间的信息调度功能全部由硬件自动完成。主存-辅存层次的调度目前广泛采用虚拟存储技术。

### **存储器结构**
* 结构：
    + 第一层：通用寄存器堆；
    + 第二层：指令与数据缓存栈；
    + 第三层：高速缓冲存储器；
    + 第四层：主存储器（DRAM）；
    + 第五层：联机外部存储器（硬磁盘机）；
    + 第六层：脱机外部存储器（磁带、光盘存储器等）；

### **半导体存储器**
* RAM(random access memory):
    + SRAM(static random access memory)
        - SRAM采用电阻分压原理进行存储，基本存储电路为6个MOS管组成1bit；
        - 优点：工作特点是读写速度非常的快，只要电源存在，数据就不会丢失；
        - 缺点：缺点是集成度低、功耗大、容量小；
    + DRAM(dynamic random access memory)
        - DRAM采用电容存储信息，因为电容会不断丢失电子，因此需要设计相应的刷新电路；
        - 优点：集成度高，价格相对低廉；
        - 缺点：外围电路设计相对复杂，该电路每个1~2ms要对高电平电容重新充电；
        - DRAM的常见刷新方法：
            - 集中式：在最大刷新间隔时间内，集中安排一段时间进行刷新。但会存在CPU访存的死时间；
            - 分散式：在每个读/写周期之后插入一个刷新周期，这样可以解决CPU访存的死时间问题。但如果在最大刷新间隔时间内没有读写，会丢失数据
            - 异步式：是集中式和分散式的折中方法，分散死时间，通过刷新信号进行刷新；
* ROM(read-only memory):
    + 结构简单，存储密度高于可读写存储器；
    + 具有非易失性，所以可靠性高；

### **寄存器和存储器的区别？**
* 寄存器(SRAM)一般是8bit，或8的整数倍，在CPU内部或I/O接口中。存储器(ROM)一般称为外存，磁盘等；
* 如果寄存器在I/O接口中，每个寄存器只有端口地址，汇编语言和C语言都可以通过端口地址来访问；寄存器主要用于
* RAM断电后数据会消失，ROM断电后数据不会消失；
* 寄存器距离CPU更近，寄存器的硬件设计和内存不一样，工作方式也和内存有较大区别，寄存器的工作流程往往更加简短，主要只有找到相关的位和读取这个位；而内存的工作流程比寄存器多出很多步，每一步都会导致延迟。所以寄存器要比内存快得多。

### **Cache的作用**
* 主要解决CPU和主存速度不匹配的问题，有效提高CPU数据的吞吐率。

## 指令系统
### **指令的常用操作类型？**
* 数据传送：
    + **MOV**：传送指令通常有寄存器之间的传送；
    + **LOAD**：从内存单元读取数据到CPU寄存器；
    + **STORE**：从CPU寄存器写数据到内存单元；
* 算数和逻辑运算：加(**ADD**)、减(**SUB**)、乘(**MUL**)、除(**DIV**)、比较(**CMP**)、加1(**INC**)、减1(**DEC**)、与(**AND**)、或(**OR**)、取反(**NOT**)、异或(**XOR**)等等。
* 移位操作：主要包括算法移位、逻辑移位、循环移位；
* 转移操作：
    + **JMP**：无条件转移
    + **BRANCH**：条件转移
    + **CALL**：调用
    + **RET**：返回
    + **TRAP**：陷阱

### **寻址方式有哪些？**
* 指令寻址：寻找下一条将要执行的指令地址
    + 顺序寻址：通过程序计数器(PC)加1(1个指令字长)，自动形成下一条指令的地址。
    + 跳跃寻址：通过转移类指令实现。所谓跳跃，是指下一条指令的地址码不由程序计数器给出，而由本条指令给出下条指令地址的计算方式。
* 数据寻址：如何在指令中表示一个操作数的地址，如何用这种表示得到操作数或怎样计算出操作数的地址
    + 隐含寻址：单地址的指令格式不明显地在地址字段中指出第二操作数的地址，而规定累加器(ACC)作为第二操作数地址。
    + 立即寻址：地址字段指出的不是操作数的地址，而是操作数本身。
    + 直接寻址：指令字中的形式地址A是操作数的真实地址EA，EA=A。直接寻址的优点是简单，指令在执行阶段仅访问一次主存，不需要专门计算操作数的地址。
    + 间接寻址：间接寻址相对于直接寻址而言，指令的地址字段给出的形式不是操作数的真正地址，而是操作数有效地址所在的存储单元的地址，也就是操作数地址的地址；
    + 寄存器寻址：是指在指令中直接给出操作数所在的寄存器编号，即$EA$=$R_i$；
    + 寄存器间接寻址：是指寄存器$R_i$中给出的不是一个操作数，而是操作数所在贮存单元的地址；
    + 相对寻址：相对寻址是把程序计数器(PC)的内容加上指令格式中的形式地址A而形成的操作数的有效地址，即$EA=(PC)+A$
    + 基址寻址：基址寻址是指将CPU中基址寄存器(BR)的内容加上指令格式中的形式地址A而形成操作数的有效地址，即$EA=(BR)+A$
    + 变址寻址：变址寻址是指将有效地址EA等于指令字中的形式地址A与变址寄存器IX的内容之和，即$EA=(IX)+A$
    + 堆栈寻址：存储器中一块特定的区域，按栈的$LIFO$原则进行寻址

### **CISC和RISC的区别？**
* RISC更能充分利用VLSI芯片的面积。CISC的控制器大多采用**微程序控制**，其控制存储器在CPU芯片内所占的面积达50%以上，而RISC控制器采用**组合逻辑控制**，其硬布线逻辑只占CPU芯片面积的10%左右。
* RISC更能提高运算速度。RISC的指令数、寻址方式和指令格式种类少，又设有多个通用寄存器，采用流水线技术，所以运算速度更快，大多数指令在一个时钟周期内完成。
* RISC便于设计，可降低成本，提高可靠性。RISC指令系统简单，因此机器设计周期短；其逻辑简单，因此可靠性高。
* RISC有利于编译程序代码优化。RISC指令类型少，寻址方式少，使编译程序容易选择更有效的指令和寻址方式，并适当地调整指令顺序，使得代码执行更高效化。
* CISC的架构主要是为了兼容以前的软件，同时为了设置更复杂的新指令从而实现软件功能的硬化，这样以适应不同的应用领域。而RISC是为了减少指令种类和简化指令功能，提高指令的执行速度；
* 注意x86与ARM现如今已经没法对应归类为CISC和RISC了。这两个架构的发展均有相互借鉴。Intel引入了“微指令架构”，x86同样融合了大量RISC类型的处理设计，但是x86的CPU由于本身在硬件层面做了很大的优化，比如乱序执行、分支预测等相关工作，因此x86的CPU功耗始终要高于ARM架构。因此，智能手机的CPU普遍采用ARM架构
* 同样ARM架构的芯片，一条指令同样需要多个时钟周期，有乱序执行和多发射。“ARM和RISC的关系，只有在名字上。”

## 中央处理器

### **简述CPU主要功能**
* 中央处理器(CPU)由运算器和控制器组成。其中，控制器的功能是负责协调并控制计算机各部件执行程序的指令序列，包括取指令、分析指令和执行指令；运算器的功能是对数据进行加工。
* CPU的具体功能：
    + 指令控制：完成取指令、分析指令和执行指令的操作，即程序的顺序控制；
    + 操作控制：一条指令的功能往往由若干操作信号的组合来实现；
    + 时间控制：对各种操作加以时间上的控制；
    + 数据加工：对数据进行算数和逻辑运算；
    + 中断处理：对计算机运行过程中出现的异常情况和特殊请求进行处理；

### **阐述流水线技术**
* ![avatar](picture/%E6%B5%81%E6%B0%B4%E7%BA%BF%E6%89%A7%E8%A1%8C%E7%A4%BA%E6%84%8F%E5%9B%BE.jpg)
* 如果把一个指令拆分成“取指令-指令译码-执行指令”这样三个部分，那这就是一个三级的流水线。这样一来可以不用把时钟周期设置成整条指令执行的时间，而是拆分成完成这样的一个一个小步骤的时间。同时，每一个阶段的电路在完成对应的任务之后，也不需要等待整个指令执行完成，而是可以直接执行下一条指令的对应阶段。（大白话：假如一个时钟周期设置为CPU所有指令中最复杂的那条指令的周期，那么CPU的指令执行效率会很低，就好比体育课体测跑1000米，老师要等到最慢的那个人跑完才能够进入下一个项目）
* 假如拆分成了五级流水线，这就表示我们在同一个时钟里面，同时运行五条指令的不同阶段。这个时候，虽然执行一条指令的时钟周期变成了5，但是可以通过提高CPU主频的方式提高工作效率。这样不需要确保最复杂的那条指令在时钟周期里面执行完成，而只要保障一个最复杂的流水线级的操作，在一个时钟周期内完成就好了。
* 像我们现代的ARM或者Intel的CPU，流水线级数都已经达到14级。
* 从原理来看，基本原理和多道程序处理过程相类似，流水线技术提高了CPU的“吞吐率”，宏观上来看CPU好像在同一时间，执行多条不同的指令。微观上来看，CPU内部，类似于生产流水线，不同分工的组件不断处理上游传递下来的内容，而不需要等待单件商品生产完成之后，再启动下一件商品的生产过程。

### **流水线越多，并行度就越高？是否流水段越多，指令执行越快？**
* 增加流水线深度其实是有性能成本的，每个流水段之间会存在流水线寄存器用于传输数据。这一开销会加长一条指令的整个执行时间，而且当指令间逻辑上存在相互依赖时，开销会更大；
* 流水段间控制逻辑变多、变复杂（流水线越多，相应会产生冒险(Hazard)，那么由于不同指令之间可能会相互依赖，因此如何让指令并行，即乱序执行，是一个很大的挑战）。用于流水线优化和存储器冲突处理的控制逻辑将随流水段的增加和增加，这可能导致用于流水段之间控制的逻辑比段本身的控制逻辑更加复杂；
* 提升流水线深度，为了达到原有的性能，往往同时提高CPU主频。提高CPU主频和复杂控制逻辑导致的晶体管数量的增加会导致功耗的上升。
* 实际案例：2000年前Intel发布的Pentium 3处理器的流水线深度是11级，同时期AMD的Athlon 1000主频有1Ghz左右，Intel为了赶超AMD发布的Pentium 4处理器最高采用了31级的流水线，主频最高达到了3.8Ghz，但是虽然性能提高上去了，但是实际上相同主频下对比AMD并未有特别大的提升，反而增加很大的CPU功耗，那时候笔记本电脑的散热和续航能力是一个巨大的问题；（理想和现实的差距）

### **为什么会产生冒险？**
* 流水线以多周期处理器为基础，按照阶段划分，单个周期内可能会同时处理多条指令。在这样复杂而又紧密快速的运行环境下，就会出现一些不可能避免的冲突，也就是我们所说的冒险。
* 冒险主要分为三类冒险：
    + 结构冒险(Structural Hazard): 
        - 同cycle阶段冲突：因为指令不同导致clock cycle不同，导致相同（流水段）阶段在同一个clock cycle中出现。然而在同一cycle内，一阶段仅允许处理一条指令，因此会产生冲突。
            - 例如，下图中第三条**lw**指令与第四条**or**指令在 cycle 7 时都是**WB**，则会产生结构冒险。
            - ![avatar](picture/%E7%BB%93%E6%9E%84%E5%86%92%E9%99%A9.png)
            - 解决措施：保证每一条指令永远都有5个阶段就可以了，对于那些缺失阶段数的指令，我们插入一条NOP指令。NOP指令是一条空指令，相当于处理器不会干任何事情。
        - Memory访问冲突：在**IF**（取指令）阶段，指令获取将会访问内存，**MEM**（访问内存）阶段（如有）指令也会访问内存，此时就有可能造成冲突；
            - 解决措施：借助哈佛架构的思路，将程序指令存储和数据存储分开，使得各自独立访问，从而解决冲突；具体做法是将Cache分为指令缓存(Instruction Cache)和数据缓存(Data Cache)两个部分。
        - Register读写访问冲突：对于同一寄存器而言，**ID**阶段会读取寄存器的值，而**WB**阶段需要将值写回寄存器，因此产生访问冲突。
            - 解决措施：我们规定用时钟上升沿出发**Write**，下降沿触发**Read**，从而将这两类冲突完全分开。
    + 数据冒险(Data Hazard): 
        - Register数据读写顺序引起的冒险：对Register的读写顺序不符合逻辑引起数据错误；
            - 解决措施：通过操作数前推(Operand Forwarding)技术或操作数旁路(Operand Bypassing)：相当于将提前计算好的数据通过额外的一条数据通路输送到对应的地方，并且这条数据通路由控制信号严格把控；
        - 真正的数据冒险(True Data Hazard)： 转发技术无法解决的问题，就是数据并没有提前被计算好。
            - 解决措施：停顿流水线(stall)，但停顿的次数越多，处理器的效率就会越低下。一般不到万不得已，我们一般不采用流水线停顿的做法来解决冒险问题；但流水线停顿的方法属于笨方法，解决措施有乱序执行技术，让CPU自己动态去调度先执行哪些指令，指令执行的先后顺序，不再和它们在程序中的顺序有关，前提是只要不破坏数据依赖关系就可以了。
    + 控制冒险(Control Hazard)：取指令和指令译码操作可能会出现停顿
        - Jump指令停顿：在流水线处理器中如果遇到**jump**指令，处理器是没有办法100%找到需要跳转指令的准确地址，因为有可能这条指令已经被清空了，也有可能还没有进入**IF**阶段。
            - 解决措施：停顿流水线解决；
            - 实际情况: if-else
            - ``` C
                if(r==0){
                    a==1;
                }
                else {
                    a=2;
                }
              ``` 
            - **JMP**后的指令是否应该顺序加载执行，在流水线中往往无法得知。要等待**JMP**指令执行完成，更新PC寄存器之后，我们才能知道。
        - Branch指令预测：对于**Branch**指令，我们在**ID**阶段就能准确知道需要跳转指令的地址，但是我们不知道两个比较的寄存器的值是否存在数据冒险，因此无法立刻判断是否要跳转。
            - 解决措施：采用动态预测(Dynamic Prediction)方式给出控制信号来提前决定此时此刻是否需要跳转指令，预测错误就停顿流水线。动态预测引入了一个状态机来存储历史状态；
            - 实际情况：for循环的嵌套；

### **为什么循环嵌套的改变会影响性能？**
```java
public class BranchPrediction {
    public static void main(String args[]) {        
        long start = System.currentTimeMillis();
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j <1000; j ++) {
                for (int k = 0; k < 10000; k++) {
                }
            }
        }
        long end = System.currentTimeMillis();
        System.out.println("Time spent is " + (end - start));
                
        start = System.currentTimeMillis();
        for (int i = 0; i < 10000; i++) {
            for (int j = 0; j <1000; j ++) {
                for (int k = 0; k < 100; k++) {
                }
            }
        }
        end = System.currentTimeMillis();
        System.out.println("Time spent is " + (end - start) + "ms");
    }
}
```
``` java console
Time spent in first loop is 5ms
Time spent in second loop is 15ms
```
* 每次循环都会有一个**CMP**和**JLE**指令，每一个**JLE**指令就意味着，要比较条件码寄存器的状态，决定是顺序执行代码，还是跳转到另外一个地址。也就是说在每一次循环发生的时候，都会有一次**Branch**
* ![avatar](picture/%E5%8A%A8%E6%80%81%E5%88%86%E6%94%AF%E9%A2%84%E6%B5%8B.jpg)

### **什么是多发射(Mulitple Issue)和超标量(Superscalar)**
* 多发射和超标量技术实质上是以空间换时间；
* 多发射技术是指同一时间，同时把多条指令发射(Issue)到不同的译码器或者后续处理的流水线中去。
* 超标量技术是指在一个周期内取出多条指令并行执行，通过内置多条流水线来同时执行多个处理。

## 总线
### **什么是总线宽度、总线带宽、总线复用、信号线数？？**
* 总线宽度：数据总线的根数，一般是8的倍数；
* 总线带宽：即总线数据传输率，总线上每秒能够传输的最大字节量；
* 总线复用：一条信号线上分时传送两种信号。例如数据总线和地址总线的分时复用；
* 信号线数：地址总线、数据总线和控制总线三种总线的线数之和。 

## 输入/输出系统
### **中断嵌套是什么？**
* 中断嵌套是指中断系统正在执行一个中断服务时，有另一个优先级更高的中断提出中断请求，这时会暂时终止当前正在执行的级别较低的中断源的服务程序，去处理级别更高的中断源，待处理完毕，再返回到被中断了的中断服务程序继续执行的过程。