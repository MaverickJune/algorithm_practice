graph = {
    'A': ['B'],
    'B': ['A', 'C', 'H'],
    'C': ['B', 'D'],
    'D': ['C', 'E', 'G'],
    'E': ['D', 'F'],
    'F': ['E'],
    'G': ['D'],
    'H': ['B', 'I', 'J', 'M'],
    'I': ['H'],
    'J': ['H', 'K'],
    'K': ['J', 'L'],
    'L': ['K'],
    'M': ['H']
}

visited = list()

def dfs(graph, source):
    visited.append(source)
    print(source + " ")
    
    for neighbor in graph[source]:
        if neighbor not in visited:
            dfs(graph, neighbor)
            
dfs(graph, 'A')