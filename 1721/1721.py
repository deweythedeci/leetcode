from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        node = head
        size = 0
        nodes = []
        while(node != None):
            nodes.append(node)
            node = node.next
            size += 1
        temp = nodes[k-1].val
        nodes[k-1].val = nodes[size-k].val
        nodes[size-k].val = temp
        return head