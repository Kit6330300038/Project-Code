public class InvoiceTest 
{
    public static void main(String[] args) 
    {   
        Customer living1 = new Customer("001","VigritV.1","Jidlorn");                 //  |     
        Customer living2 = new Customer("010","VigritV.2","Jidlorn");                 //  |   
        Invoice num1 = new Invoice("2256",living1);                                   //  |  
        Invoice num2 = new Invoice("1478",living2);                                   //  |
        Invoice num3 = new Invoice("14689",new Customer("100","VigritV.3","Jidlorn"));//  |
        Product pro1 = new Product("123456","JUST AN ITEM V.1",26);                   //  |
        Product pro2 = new Product("16546","JUST AN ITEM V.2",63);                   //  | 
        Product pro3 = new Product("1657127456","JUST AN ITEM V.3",222);                  //  |
        Product pro4 = new Product("723476","JUST AN ITEM V.4",1);                    //  |
        Product pro5 = new Product("325756","JUST AN ITEM V.5",18);                   //  create 2 customer 3 invoice and 5 product 
        num1.addItem(pro3,4);           //  |
        num1.addItem(pro1,2);           //  |
        num1.addItem(pro2, 1);          //  |
        num1.addItem(pro5, 3);          //  |
        num2.addItem(pro1,22);          //  |
        num2.addItem(pro2, 1);          //  |
        num2.addItem(pro5, 8);          //  |
        num3.addItem(pro4,65);          //  |
        num3.addItem(pro1,6);           //  |
        num3.addItem(pro2, 3);          //  |
        num3.addItem(pro5, 5);          // additem
        num1.print();           //  |
        num2.print();           //  |
        num3.print();           //  call print method
    }
}
