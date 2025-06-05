# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        dummy = ListNode(0)
        dummy.next = head
        current = dummy

        while current.next and current.next.next:
            first = current.next
            second = current.next.next

            first.next = second.next
            second.next = first
            current.next = second

            current = first

        return dummy.next

def build_linked_list(values):
    if not values:
        return None
    head = ListNode(values[0])
    current = head 
    for v in values[1:]:
        current.next = ListNode(v)
        current = current.next
    return head

def print_linked_list(head):
    vals = []
    while head:
        vals.append(str(head.val))
        head = head.next
    print(" -> ".join(vals))

if __name__ == "__main__":
    values = [1,2,3,4]
    head = build_linked_list(values)
    print("Original List: ") 
    print_linked_list(head)

    solution = Solution()
    swapped_head = solution.swapPairs(head)

    print("List After Swapping PIRS: ")
    print_linked_list(swapped_head)
    