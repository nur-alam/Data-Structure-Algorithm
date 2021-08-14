// node creator class / blue print of a node class
class Node {
    constructor(value) {
        this.value = value;
        this.next = null;
    }
}

class SinglyLinkedList {
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
    break() { console.log(this); }
    push(value) {
        const newNode = new Node(value);
        if(this.len) {            
            this.tail.next = newNode;
        } else {
            this.head = newNode;
        }
        this.tail = newNode;
        this.len++;
        return this;
    }
    pop() {
        if(!this.len) {
            return this;
        } else {
            let currentNode = this.head;
            let secondLastNode = this.head;
            while(currentNode.next) {
                secondLastNode = currentNode;
                currentNode = currentNode.next;
            }
            secondLastNode.next = null;
            this.tail = secondLastNode;
            this.len--;
            if(!this.len) {
                this.head = this.tail = null;
            }
            return this;
        }
    }
    unshift(value) {
        const newNode = new Node(value);
        if (!this.len) {
            this.tail = newNode;
        } else {
            newNode.next = this.head;
        }
        this.head = newNode;
        this.len++;
        return this;
    }
    shift() {
        if (!this.len) {
            return this;
        } else {
            const nodeToRemove = this.head;
            this.head = this.head.next;
            this.len--;
            if (!this.len) {
                this.tail = null;
            }
            return this;
        }
    }
    get(index) {
        if (!this.len || index < 0 || index > this.len) {
            return this;
        } else {
            let currentNode = this.head;
            let count = 0;
            while (count < index) {
                currentNode = currentNode.next;
                count++;
            }
            return currentNode;
        }
    }
    set(index, value) {
        let currentNode = this.get(index);
        if(!currentNode) {
            return null;
        }
        currentNode.value = value;
        return currentNode;
    }
    insert(index, value) {
        if(index < 0 || index > this.len) 
            return this;
        else if (index === 0) 
            return this.unshift(value);
        else if (index === this.len) 
            return this.push(value);
        else {
            const newNode = new Node(value);
            const prevNode = this.get(index - 1);
            newNode.next = prevNode.next;
            prevNode.next = newNode;
            this.len++;
            return this;
        }
    }
    remove(index) {
        if(index < 0 || index >= this.len) 
            return this;
        else if (index === 0) 
            return this.shift();
        else if (index === this.len - 1) 
            return this.pop();
        else {
            const prevNode = this.get(index - 1);
            const nodeToRemove = prevNode.next;
            prevNode.next = nodeToRemove.next;
            this.len--;
            return this;
        }
    }
}

const newSl = new SinglyLinkedList();
newSl.push(10).push(20).push(30).push(40)
    .print().pop().pop().pop().pop().print();
    console.log('len ', newSl.get(0));
// console.log((newSl.set(0, 50))); newSl.print();
    // .print()
    // .pop().pop().pop()
    // .print();
    // newSl.print().pop().pop().pop().print().unshift(5).print().unshift(0).print();
    // newSl.print().shift().shift().print();//.push(20).shift().print();
// console.log(newSl);
// setInterval(() => {
//     newSl.push();
//     newSl.print();
// },5000)