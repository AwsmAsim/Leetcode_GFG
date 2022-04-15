class Solution:
    def invalidTransactions(self, transactions: List[str]) -> List[str]:
        from collections import defaultdict, deque
        
        transactions.sort(key=lambda x: int(x.split(',')[1]))
        invalid_transactions_ids = set()
        
        transaction_history = defaultdict(deque)  # [id, city, time]
        
        
        for i in range(len(transactions)):
            name, time, amount, city = transactions[i].split(',')
            
            time = int(time)
            amount = int(amount)
            
            name_history = transaction_history[name]
            
            while (name_history and time - name_history[0][2] > 60):
                name_history.popleft()

            is_invalid = False

            for prev_id, prev_city, _ in name_history:
                if prev_city != city:
                    invalid_transactions_ids.add(prev_id)
                    is_invalid = True

            if is_invalid or amount > 1000:
                invalid_transactions_ids.add(i)
                
            name_history.append((i, city, time))
            
        answer = [transactions[i] for i in invalid_transactions_ids]
        
        return answer