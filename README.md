# 寿命预测模块
## 一、模块功能简介
威布尔分布(*Weibull distribution*)在可靠性分析和寿命检验领域应用广泛。本模块借鉴威布尔分布公式，推导得出电池循环和储存容量衰减及阻抗增加的经验公式，并利用退火优化算法及广泛应用于非线性最小二乘问题的列文伯格&马夸尔特(*Levenberg-Marquardt*)算法，拟合公式中的参数，最后利用拟合公式进行电池寿命的预测及计算。

## 二、算法介绍
### 2.1 模拟退火优化算法(*Simulated-Annealing Algorithm*)
模拟退火本质是一种贪心算法，但是它的搜索过程引入了随机因素。模拟退火算法以一定的概率来接受一个比当前解要差的解，因此有可能会跳出这个局部的最优解，达到全局的最优解。
我们将一次向较差解的移动看做一次温度跳变过程，我们以概率P来接受这样的移动。在用固体退火模拟组合优化问题，将内能E模拟为目标函数值 f，温度T演化成控制参数 t，即得到解组合优化问题的模拟退火演算法：由初始解 i 和控制参数初值 t 开始，对当前解重复“产生新解→计算目标函数差→接受或丢弃”的迭代，并逐步衰减 t 值，算法终止时的当前解即为所得近似最优解，这是基于蒙特卡罗迭代求解法的一种启发式随机搜索过程。退火过程由冷却进度表(Cooling Schedule)控制，包括控制参数的初值 t 及其衰减因子Δt 、每个 t 值时的迭代次数L和停止条件S。
以求最小值为例
***step 1*** 选定初始解x~0~,令当前解x~i~=x~0~;当前迭代步数k=0;当前温度t~k~=t~max~
***step 2*** 若在该温度达到内循环停止条件，则转第三步；否则随机生成新解x~j~，计算$\delta=f(x_j)-f(x_i)$,若$\delta<=0$,则x~i~=x~j~,否则若$e^{\frac{-\delta}{t_k}}>random(0,1)(0到1之间的随机数)$,则x~i~=x~j~,重复第二步
***step 3*** k=k+1,t~k+1~=d(t~k~)(表示温度下降的函数),若满足终止条件，转第四步，否则转第二步
***step 4*** 输出计算结果，停止
###2.2列文伯格&马夸尔特算法(*Levenberg-Marquardt Algorithm*)
L&M算法是一种具有二次收敛性质的广泛用于解决非线性最小二乘问题的优化算法，它是利用梯度求最大（小）值的算法。它同时具有梯度法和牛顿法的优点。当λ很小时，步长等于牛顿法步长，当λ很大时，步长约等于梯度下降法的步长。它属于优化算法中的信赖域方法，具有收敛速度快，但易陷入局部最优解的特点，且初值设定不当，会造成结果偏差较大。
以求最小值为例
***step 1*** 给出初始解x~0~，$\lambda>0,\epsilon>0,k:=0$
***step 2*** 若终止条件满足，则输出有关信息，停止迭代
***step 3*** 计算$Jacobi$矩阵$J_k$，求解方程$(J_k^TJ_k+\lambda_kI)d=-J_k^Tr_k$，得出$d_k$
***step 4*** 计算得出用于$\mu_k$修正的$\Gamma$,
***step 5*** 若$0<\Gamma<0.25$,则$\lambda_{k+1}:=4\lambda_k$;若$\Gamma>0.75$，则$\lambda_{k+1}:=\lambda_k/2$;否则 $\lambda_{k+1}:=\lambda_{k}$
***step 6*** 若$\Gamma<=0$,则$x_{k+1}:=x_k$;否则，$x_{k+1}:=x_k+d_k,k:=k+1$，转步2.

## 三、程序流程
### 3.1 程序说明
结合该问题实际特点，考虑到退火算法具有全局搜索最优值但耗费时间长，L&M算法具有二次收敛的性质，但容易陷入局部最优解，且迭代过程对初值敏感的特点，本程序同时选用模拟退火及列文伯格&马夸尔特算法进行求解
### 3.2 拟合公式
循环容量衰减公式：
$$ 
Capacity(\theta:t,tem,C)=e^{-{e^{C1-\frac{C3}{tem}}}*{(t*C)^{C1}}-{e^{C5-\frac{C6}{tem}}}*{(t*C)^{C4}}}
$$
循环阻抗增加公式：
$$

Impedance(\theta:t,tem,C)=1+{e^{C2-\frac{C3}{tem}}}*{(t*C)^{C1}}+{e^{C5-\frac{C6}{tem}}}*{(t*C)^{C4}}\\\theta:拟合参数C1...C6\\tem:温度,t:循环次数,C:倍率,Capacity:容量,Impedance:阻抗
$$
储存容量衰减公式：
$$
Capacity(\theta:t,tem,SOC)=e^{{-e^{C4-\frac{C3}{tem}-C2*SOC}*t^{C1}}}
$$
储存阻抗增加公式
$$
Impedance(\theta:t,tem,SOC)=1{+e^{C4-\frac{C3}{tem}-C2*SOC}*t^{C1}}\\\theta:拟合参数C1...C4\\tem:温度,t:循环次数,Impedance:阻抗,Capacity:容量
$$
###3.2算法步骤
下面以==循环容量衰减公式拟合+预测==为例说明该程序流程算法步骤
####数学问题抽象
#####拟合目标函数
$$
r(\theta)=Capacity_{measure}-Capacity(\theta:t,tem,C)\\
min f(\theta)=\frac{1}{2}*\sum_{i = 0}^{N}r_i(\theta)^{2}\\
\theta:C1...C6,N:测试数据点个数
$$
####算法流程图
```flow
  st=>start: Start
  input=>inputoutput: 输入数据点[t,tem,C,capacity],
  任意给定初始值C1...C6
  input2=>inputoutput: 输入新工况数据点[t,tem,C,capacity]
  及拟合得到的C1...C6
  op=>operation: 退火算法求得(C1...C6)new,
  (C1...C6)=(C1...C6)new
  op1=>operation: 数据清洗
  op2=>operation: L&M法迭代
  op3=>operation: 通过公式计算得到新工况寿命衰减曲线
  op4=>operation: 校正原工况曲线
  sub1=>subroutine: (C1...C6)k+1=(C1...C6)k
  cond=>condition: 是否满足收敛条件？
  e=>end
  st->input->op1->op->op2->cond
  cond(yes)->op4->input2->op3->e
  cond(no)->sub1->op2
```

**step 1：** 读取数据并赋初值
```c
//读取数据接口
#include"Reader.h"
vector<double> ReadFileInfo(string in_name)//读取文件数据
vector<string> ReadFileName(vector<double>& t, vector<double>& tem, vector<double>& C, vector<double>& capacity, vector<double>& impedance, vector<double>& force)//读取文件名称
//赋初值
double C1_ = 0, C2_ = 0, C3_ = 0, C4_ = 0, C5_ = 0, C6_ = 0,
```
**step 2:** 退火算法进行全局搜索求得新的C1...C6
```c
//退火算法
#include"Capacity_SA.h"
//退火算法
void Capacity_SA(vector<VectorXd> obsPt, double& C1, double& C2, double& C3, double& C4, double& C5, double& C6);
//范围函数，任意给定一个Lower~Upper范围的值
double Capacity_rnd(double Lower, double Upper);
```
**step 3** L&M算法进行局部搜索确定最终拟合参数C1...C6
```c
//L&M接口
namespace Cycle_Capacity
{
	class Runtime   //计算每步迭代时间
	{
	public:
		void Start();
		void Stop();
		double Duration();
	private:
		steady_clock::time_point tstart;
		steady_clock::time_point tend;

	};


	class LevenbergMarquardt  //L&M算法
	{
	public:
        //参数初始化
		LevenbergMarquardt(double dC1, double dC2, double dC3, double dC4, double dC5, double dC6);
        //确定收敛条件
		void SetParameters(double sEpsilon1, double sEpsilon2, int sMaxIter, bool sIsout);
        //录入数据点
		void AddObservation(const double tem, const double t, const double C, const double capacity);
        //计算Jocabian矩阵
		void CalcJ_fx();
        //计算H_和g_
		void CalcH_g();
		double GetCost();
        //计算剩余函数值
		double F(double C1, double C2, double C3, double C4, double C5, double C6);
        //计算最优点附近近似的正定二次函数值
		double L0_L(Eigen::VectorXd h);
        //迭代求解
		vector<double> Slove();
	public:
        //收敛误差
		double epsilon1, epsilon2;
        //最大迭代步数
		int MaxIter;
        //温度、倍率、循环次数数据点
		vector<VectorXd> obsPt;
        //参数
		double C1, C2, C3, C4, C5, C6;
		bool isOut;
	private:
        //剩余函数
		MatrixXd fx_;
        //Jocabian矩阵
		MatrixXd J_;
        //Hessian阵
		MatrixXd H_;
		VectorXd g_;
	};
}
```
**step 4** 校正原工况曲线
```c
//写入数据，校正原函数曲线
#include"Writer.h"
void Write(vector<double>& Parameter, vector<string>& In_name)
```

**step 5** 新工况寿命预测
```c
//写入数据，输出新工况寿命预测数据
#include"Write.h"
void Write(vector<double>& Parameter, vector<string>& In_name)
```
