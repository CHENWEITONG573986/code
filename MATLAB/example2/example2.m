clc;clear;close all;

%% 读取表格的相关函数汇总
% 作者：HAO999
% 时间：2023.08.14
% 汇总了部分表格读取函数，后续可能会在此例程中添加数据处理教学

%% 读取excel数据
%dataTable1=xlsread("附件1 近5年402家供应商的相关数据.xlsx",'企业的订货量（m³）'); %读取excel表格 

%dataTable2=readmatrix("附件1 近5年402家供应商的相关数据.xlsx");

dataTableOrder=readtable("附件1 近5年402家供应商的相关数据.xlsx",'Sheet','企业的订货量（m³）');
dataTableSupply=readtable("附件1 近5年402家供应商的相关数据.xlsx",'Sheet','供应商的供货量（m³）');

tableOrder=dataTableSupply(:,3:end);
tableSupply=dataTableOrder(:,3:end);
%%
dataOrder=table2array(tableOrder);
dataSupply=table2array(tableSupply);
%% 求最大值,最小值，平均值
dataOrderMax=max(dataOrder');
dataSupplyMax=max(dataSupply');
% (供应商供货量-企业订货量)平均值
dataMax=mean(dataOrder-dataSupply);

% 找所有供货量不为0的次数
% 1.先找第一行（即第一个供货商不为0）的次数
dataSupply_1=dataSupply(1,:);
dataNot0_1=find(dataSupply_1~=0);
numNot0_1=length(dataNot0_1);
% 2.再写一个循环，找出所有行不为0的次数
numNot0=zeros(size(dataSupply,1),1);
for i=1:size(dataSupply,1)
    dataSupply_1=dataSupply(i,:);
    dataNot0_1=find(dataSupply_1~=0);
    numNot0_1=length(dataNot0_1);
    numNot0(i)=numNot0_1;
end

numBig2=zeros(size(dataSupply,1),1);
for i=1:size(dataSupply,1)
    dataSupply_1=dataSupply(i,:);
    dataNot0_1=find(dataSupply_1>2);
    numNot0_1=length(dataNot0_1);
    numBig2(i)=numNot0_1;
end

%% 找到矩阵缺失值并删除所在行列

load("带缺少数据.mat");
index=isnan(data_nan);
index1=find(sum(index')~=0);
data_nan1=data_nan;
data_nan1(index1,:)=[];

%% 分布找出属于A,B,C的数据，并储存起来
% 1.将文字标签改为数字标签
dataABC=dataTableOrder(:,2);
dataABC_num=table2array(dataABC);
dataTongji=tabulate(dataABC_num);
for i=1:size(dataTongji,1)
    str(1,i)=dataTongji(i,1);
end

for NN=1:length(str)
    idx=find(ismember(dataABC_num,str(1,NN)));
    datashuju(idx)=NN;
end

%
%找出ABC

for i=1:size(dataTongji,1)
    A(i)={find(datashuju==i)};
end

%
% 数据标准化
stdData=zscore(dataOrder); %列标准化
stdData1=mapminmax(dataOrder',0,1); %行标准化

%
%假如仅对B进行标准化
dataB=zscore(dataOrder(A{1,1},:));
A{2,1}=dataB;




