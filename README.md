<h2>Game C++: Catching Fruit </h2> (Visual Studio 2017)

1, Tổng quan
* Sử dụng thư viện SDL:
  - đọc "Huongdancaidat.txt" để cài đặt thư viện SDL vào Visual Studio
* Luật chơi:
  - Di chuyển ếch để ăn hoa quả rơi
  - Ăn hoa quả +1 điểm, ăn ngôi sao +5 điểm
  - Đụng phải bom sẽ game over
  - Bỏ sót 3 hoa quả  sẽ game over 
  - Bỏ sót ngôi sao không bị trừ điểm

* Gồm 4 module và main.cpp:
   - (game.h , game.cpp): Khởi tạo các đối tượng biến chung và các hàng chung
   - (BaseObject.h, BaseOject.cpp): các hàm cơ sở cho đối tượng
   - (MainObject.h, MainObject.cpp): khởi tạo các thông số của đối tượng chính (ếch), các hàm di chuyển của đối tượng chính, dùng class
   - (FruitObject.h. FruitObject.cpp): khởi tạo các thông số của đối tượng hoa quả, các hàm rơi, tốc độ rơi, reset hoa quả, dùng class
   - main.cpp: hàm xử lý chính, gồm: hàm menu, hàm gameover, xử lý di chuyển đối tượng chạy qua lại, ghi điểm số.
   
2, Mô tả
* Menu

  <td><img src="/Catching%20Fruit/main.PNG" width="300"></td>
* Màn hình chơi
  <td><img src="/Catching%20Fruit/main1.png" width="300">             <img src="/Catching%20Fruit/main2.png" width="300"></td>
* Game over
  <td><img src="/Catching%20Fruit/gameover.png" width="300"></td>
