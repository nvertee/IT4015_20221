Hướng dẫn của mã dịch SHIFT CIPHER:
  - encryp() : hàm mã hóa: Y = (X+K) mod 26
  - decryp() : hàm giải mã: X = (Y-K) mod 26. 
        Vì trong lập trình, có thể Y-K bị âm nên trong code có thực hiện cộng Y-K với 26*K để đảm bảo luôn dương mà không ảnh hưởng đến kết quả X.
  - crack() : hàm phá mã, thử tất cả 26 khả năng.

--------------------------------------------------------------
