clc;
clear;
%%矩阵
A = [1 2 3;  4 5 6; 7 8 9];
B = A';
C = A(:);
D = inv(A);
%%
E = zeros(10,5,3);
% rand生产均分布的伪随机数
E(:,:,1) = rand(10,5);
% randi生成均匀分布的伪随机整数
E(:,:,2) = randi(5,10,5);
% randn生成标准正态分布的伪随机数
E(:,:,3) = randn(10,5);

%%元胞数组
A = cell(1,6);
A{2} = eye(3);
A{5} = magic(5);