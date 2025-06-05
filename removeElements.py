# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: Optional[ListNode]
        :type val: int
        :rtype: Optional[ListNode]
        """
        temp = ListNode(0)
        temp.next = head
        prev, curr = temp, head
        while curr:
            if curr.val == val: prev.next = curr.next
            else: prev = curr
            curr = curr.next
        return temp.next

def build_linked_list(values):
    """根据列表生成链表"""
    if not values:
        return None
    head = ListNode(values[0])
    curr = head
    for value in values[1:]:
        curr.next = ListNode(value)
        curr = curr.next
    return head

def print_linked_list(head):
    """打印链表节点值"""
    values = []
    curr = head
    while curr:
        values.append(str(curr.val))
        curr = curr.next
    print("->".join(values))

if __name__ == '__main__':
    # 构造链表：1->2->6->3->4->5->6
    values = [1, 2, 6, 3, 4, 5, 6]
    head = build_linked_list(values)
    print("原链表:")
    print_linked_list(head)

    # 调用 removeElements 移除所有值为 6 的节点
    sol = Solution()
    new_head = sol.removeElements(head, 6)
    print("移除所有 6 后的链表:")
    print_linked_list(new_head)