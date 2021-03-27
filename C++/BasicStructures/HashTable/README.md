# HashTable

Simple hashTable implementation using a Double Linked List internally to support key collision.
Collision can happens in two ways:
- Same Key: In this case the element already present into HashTable will be replaced by the new one
- Different Key: No problem because the GET operation search for key

Methods:

- put: Add an element to hashtable, firstly creating/getting the double linked list into its bucket
- remove: Remove the element (its node) if founded
- get: Returns Node of element if founded
- percentualFull: Return % of buckets used, taking the capacity as base
- exists: Return true if element has been founded by get operation
- getSize: Return size of hashtable, in other words, sum of size of all linked list into buckets
- empty: true if hashtable is empty
- setHashCalculator: Used to pass a function for calculate the hashCode of Key. It is not required, because exist a default calculator
