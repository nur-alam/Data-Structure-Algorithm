class Node {
    constructor(value) {
        this.value = value;
        this.prev = null;
        this.next = null;
    }
}

class doublyLinkedList {
    constructor() {
        this.head = null;
        this.tail = null;
        this.len = 0;
    }
    print() {
        let _node = this.head;
        while(_node != null) {
            console.log(_node.value);
            _node = _node.next;
        }
        this.break();
        return this;
    }
    break() { 
        console.log("===");
        // console.log(this); 
    }
    push(value) {
        const newNode = new Node(value);
        if (!this.len) {
            this.head = newNode;
            this.tail = newNode;
        } else {
            this.tail.next = newNode;
            newNode.prev = this.tail;
            this.tail = newNode;
        }
        this.len++;
        return this;
    }
    pop() {
        if(!this.len) 
            return this;
        else {
            const nodeToRemove = this.tail;
            if (this.len === 1) {
                this.head = null;
                this.tail = null;
            } else {
                this.tail = this.tail.prev;
                this.tail.next = null;
                nodeToRemove.prev = null;
            }
        }
        this.len--;
        return this;
    }
    unshift(value) {
        const newNode = new Node(value);
        if (!this.len) {
            this.head = this.tail = newNode;
        } else {
            newNode.next = this.head;
            this.head.prev = newNode;
            this.head = newNode;
        }
        this.len++;
        return this;
    }
    shift() {
        if(!this.len)
            return null;
        const nodeToRemove = this.head;
        if (this.len === 1) {
            this.head = this.tail = null;
        } else {
            this.head = nodeToRemove.next;
            this.head.prev = nodeToRemove.next = null;
        }
        this.len--;
        return this;
    }
    get(index) {
        if (!this.len || index < 0 || index >= this.len) 
            return null;
        else {
            let currentNode;
            if (index < this.len / 2) {
                let counter = 0;
                currentNode = this.head;
                while (counter < index) {
                    currentNode = currentNode.next;
                    counter++;
                }
            } else {
                let counter = this.len - 1;
                currentNode = this.tail;
                while (counter > index) {
                    currentNode = currentNode.prev;
                    counter--;
                }
            }
            return currentNode;
        }
    }
    set(index, value) {
        const currentNode = this.get(index);
        if (!currentNode)
            return this;
        currentNode.value = value;
        return this;
    }
    insert(index, value) {
        if (index < 0 || index > this.len) 
            return this;
        else if (index == 0)
            return this.unshift(value);
        else if (index === this.len) {
            return this.push(value);
        } else {
            const newNode = new Node(value);
            const prevNode = this.get(index - 1);
            const nextNode = prevNode.next;
            prevNode.next = newNode;
            newNode.prev = prevNode;
            newNode.next = nextNode;
            nextNode.prev = newNode;
            this.len++;
            return this;
        }
    }
    remove(index) {
        if (!this.len || index < 0 || index > this.len)
            return this;
        else if (index === 0) 
            return this.shift();
        else if (index === this.len - 1)
            return this.pop();
        else {
            const nodeToRemove = this.get(index);
            const prevNode = nodeToRemove.prev;
            const nextNode = nodeToRemove.next;
            nodeToRemove.prev = nodeToRemove.next = null;
            prevNode.next = nextNode;
            nextNode.prev = prevNode;
            this.len--;
            return this;
        }
    }
}

const newDl = new doublyLinkedList();

newDl.push(10).push(20).push(30).print().insert(0,5).remove(2).print();
console.log( newDl.get(3) );
//.pop().print().unshift(5).shift().shift().print();