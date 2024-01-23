#include <iostream>
#include <list> 
#include <set>
#include <map>
#include <stdlib.h>
  
int main() { 
  std::cout << "Hello World!" << std::endl; 
  return 0; 
}

class Order;
class Limit;
typedef int OrderId;
typedef int LimitPrice;

enum BuyOrSell { buy, sell };

class Order {
    public:
        Order(BuyOrSell, int, LimitPrice, int, int);
    private:
        OrderId idNumber;
        BuyOrSell buyOrSell;
        int shares;
        LimitPrice limit;
        int entryTime;
        int eventTime;
        Limit* parentLimit;
};

class Limit {
    public:
        Limit(LimitPrice);
    private:
        LimitPrice limitPrice;
        int totalVolume;
        std::list<Order> orders;
};

class OrderBook {
    public:
        OrderBook();
        bool Add(Order);
        bool Cancel(OrderId);
        bool Execute(OrderId);
        int GetVolumeAtLimit(LimitPrice, BuyOrSell) const;
        LimitPrice GetBestBid(BuyOrSell) const;


    private:
        std::set<Limit> buy;
        std::set<Limit> sell;
        Limit* lowestSell;
        Limit* highestBuy;
        std::map<LimitPrice, Limit> limitBuyMap;
        std::map<LimitPrice, Limit> limitSellMap;
        std::map<OrderId, Order> orderMap;

};

Order::Order(BuyOrSell operation, int shareCount, LimitPrice price, int entry, int event) {
    buyOrSell = operation;
    shares = shareCount;
    limit = price;
    entryTime = entry;
    eventTime = event;
    parentLimit = nullptr;
    idNumber = rand();
}

Limit::Limit(LimitPrice price) {
    limitPrice = price;
    totalVolume = 0;
}

OrderBook::OrderBook()
    : lowestSell(nullptr), highestBuy(nullptr) {}

bool OrderBook::Add(Order order) {
    std::map<LimitPrice, Limit> map;
    if (order.buyOrSell == BuyOrSell::buy) {
        map = this->limitBuyMap;
    }
}

bool OrderBook::Cancel(OrderId id) {

}

bool OrderBook::Execute(OrderId id) {

}


int OrderBook::GetVolumeAtLimit(LimitPrice limit, BuyOrSell action) const {
    std::map<LimitPrice, Limit> map;
    if (action == BuyOrSell::buy) {
        map = this->limitBuyMap;
    } else {
        map = this->limitSellMap;
    }
    
    
}

LimitPrice OrderBook::GetBestBid(BuyOrSell) const {

}

