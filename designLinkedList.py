class ListNode:
    def __init__(self, val):
        self.val = val
        self.next = None

class MyLinkedList(object):
    def __init__(self):
        self.head = None
        self.size = 0
    
    def get(self, index):
        if index < 0 or index >= self.size:
            return -1
        
        current = self.head

        for _ in range(0, index):
            current = current.next
        return current.val

    def addAtHead(self,head):
        self.addAtIndex(0, head)
    
    def addAtTail(self,val):
        self.addAtIndex(self.size, val)
    
    def addAtIndex(self,index,val):
        if index > self.size:
            return
        
        current = self.head
        new_node = ListNode(val)

        if index <= 0 :
            new_node.next = current
            self.head = new_node
        else:
            for _ in range(index - 1):
                current = current.next
            new_node.next = current.next
            current.next = new_node
        self.size += 1

    def deleteAtIndex(self, index):
        if index < 0 or index >= self.size:
            return
        current = self.head

        if index == 0:
            self.head = self.head.next
        else:
            for _ in range(0, index - 1):
                current = current.next
                current.next = current.next.next  
            self.size -= 1

    """
    def __init__(self):
        self.arr = []

    def get(self, index):
        return self.arr[index] if index < len(self.arr) and index >=0 else -1

    def addAtHead(self, val):
        self.arr.insert(0, val)

    def addAtTail(self, val):
        self.arr.append(val)

    def addAtIndex(self, index, val):
        if index == len(self.arr):
            self.addAtTail(val)
        elif index < len(self.arr) and index >= 0:
            self.arr.insert(index,val)

    def deleteAtIndex(self, index):
        if index < len(self.arr) and index >= 0:
            self.arr.pop(index)
"""
myLinkedList =  MyLinkedList()
print(myLinkedList.addAtHead(1))
print(myLinkedList.addAtTail(3))
print(myLinkedList.addAtIndex(1, 2))
print(myLinkedList.get(1))              
print(myLinkedList.deleteAtIndex(1))
print(myLinkedList.get(1))
