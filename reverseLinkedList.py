# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def reverseList(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        cur = head 
        pre = None
        while cur:
            temp = cur.next
            cur.next = pre
            pre = cur
            cur = temp
        return pre


def build_linked_list(values):
    """根据列表创建链表，并返回头结点"""
    if not values:
        return None
    head = ListNode(values[0])
    current = head
    for v in values[1:]:
        current.next = ListNode(v)
        current = current.next
    return head

def print_linked_list(head):
    """打印链表的所有节点值"""
    current = head
    values = []
    while current:
        values.append(str(current.val))
        current = current.next
    print(" -> ".join(values))

if __name__ == "__main__":
    # 构造链表 [1, 2, 3, 4, 5]
    values = [1, 2, 3, 4, 5]
    head = build_linked_list(values)
    print("Original Linked List:")
    print_linked_list(head)
    
    # 反转链表
    solution = Solution()
    reversed_head = solution.reverseList(head)
    
    print("Reversed Linked List:")
    print_linked_list(reversed_head)
