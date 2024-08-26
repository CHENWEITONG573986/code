import torch
import random
import matplotlib.pyplot as plt
from tqdm import tqdm
import numpy as np
import networkx as nx
import torch.nn.functional as F
from torch_geometric.nn import GCNConv
 
 
def create_mock_data(number_of_nodes, edge_per_node, in_channels):
    """
    Creating a mock feature matrix and edge index.
    """
    graph = nx.watts_strogatz_graph(number_of_nodes, edge_per_node, 0.5)
    edge_index = torch.LongTensor(np.array([edge for edge in graph.edges()]).T)
    X = torch.FloatTensor(np.random.uniform(-1, 1, (number_of_nodes, in_channels)))
    return X, edge_index
 
 
def create_mock_edge_weight(edge_index):
    """
    Creating a mock edge weight tensor.
    """
    return torch.FloatTensor(np.random.uniform(0, 1, (edge_index.shape[1])))
 
def create_mock_target(number_of_nodes, number_of_classes):
    """
    Creating a mock target vector.
    """
    return torch.LongTensor([random.randint(0, number_of_classes-1) for node in range(number_of_nodes)])
 
 
class GCN(torch.nn.Module):
    def __init__(self, node_features, input_size, num_classes):
        super(GCN, self).__init__()
        self.conv1 = GCNConv(node_features, input_size)
        self.MLP = torch.nn.Sequential(
            torch.nn.Linear(input_size, input_size // 2),
            torch.nn.ReLU(inplace=True),
            torch.nn.Linear(input_size // 2, input_size // 4),
            torch.nn.ReLU(inplace=True),
            torch.nn.Linear(input_size // 4, num_classes))
        self.relu = torch.nn.ReLU()
 
 
    def forward(self, x, edge_index, edge_weight):
        '''
        GCN
        '''
        x = self.relu(self.conv1(x, edge_index))
        x = F.dropout(x, training=self.training)
        x = self.MLP(x)
 
        return F.log_softmax(x, dim=1)
 
 
node_features = 100
node_count = 1000
input_size = 32
num_classes = 10
edge_per_node = 15
epochs = 200
learning_rate = 0.01
weight_decay = 5e-4
 
model = GCN(node_features=node_features, input_size=input_size, num_classes=num_classes)
 
optimizer = torch.optim.Adam(model.parameters(), lr=learning_rate, weight_decay=weight_decay)
 
model.train()
 
loss_list = []
for epoch in tqdm(range(epochs)):
    optimizer.zero_grad()
    x, edge_index = create_mock_data(node_count, edge_per_node, node_features)
    edge_weight = create_mock_edge_weight(edge_index)
    scores = model(x, edge_index, edge_weight)
    target = create_mock_target(node_count, num_classes)
    loss = F.nll_loss(scores, target)
    loss_list.append(loss.item())
    loss.backward()
    optimizer.step()
 
plt.plot(loss_list)
plt.xlabel("Epoch")
plt.ylabel("MSE")
plt.title("loss")
plt.show()

