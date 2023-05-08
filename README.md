# Minesweeper

## Giới thiệu bản thân
Họ và tên: Lương Ngọc Tuấn

Mã Sinh Viên: 22021146

Lớp: K67CC

## Bài tập cuối kì môn Lập trình nâng cao (INT2215)

Tên game: Minesweeper

Đây là bài tập lớn cuối kì kết thúc học phần Lập trình nâng cao (INT2215), được viết bằng ngôn ngữ C++, sử dụng thư viện SDL2

### Cách tải và chạy code nguồn trên máy

#### Đối với Windows

Đảm bảo máy của các bạn đã được cài compiler g++ của MinGW. Nếu chưa cài đặt, các bạn có thể tham khảo video sau để cài compiler g++:
    https://www.youtube.com/watch?v=sXW2VLrQ3Bs

Sau đó các bạn mở terminal trong thư mục mã nguồn và chạy Makefile, sau đó chạy file Minesweeper.exe vừa tạo ra để chơi game
> Tùy thuộc vào cách bạn cài compiler, câu lệnh chạy Makefile có thể là 'make' hoặc 'mingw32-make'

### Chi tiết trò chơi

Trò chơi được lấy ý tưởng và cảm hứng từ game Minesweeper vốn đã rất quen thuộc với chúng ta trên hệ điều hành Windows từ xưa (Windows 95, Windows XP). Phần lớn các đoạn mã nguồn là do tôi tự viết, ngoài ra một số đoạn mã nguồn được học từ trang web: https://lazyfoo.net/tutorials/SDL

#### Cách chơi

Trò chơi bao gồm một bảng 20x20 ô, trong đó có một số ô có chứa bomb. Số lượng bomb tùy theo độ khó các bạn chọn. Nhiệm vụ của các bạn là tìm tất cả các ô chứa bomb để thắng trò chơi

Để mở một ô trên bảng, các bạn nhấn chuột trái. Nếu ô đó không chứa bomb, một hoặc một số ô sẽ được mở ra, trong ô là số lượng bomb trong 8 ô xung quanh ô đó. Khi các bạn xác định được ô chứa bomb, nhấn chuột phải để đặt cờ đánh dấu ô đó chứa bomb.

Trò chơi sẽ kết thúc khi bạn đặt cờ ở tất cả các ô chứa bomb hoặc khi bạn nhấn vào ô chứa bomb.

#### Một số hình ảnh trong game

!(/example/Screenshot 2023-05-08 152838.png)

!(/example/Screenshot 2023-05-08 152853.png)

!(/example/Screenshot 2023-05-08 152939.png)

!(/example/Screenshot 2023-05-08 153002.png)

!(/example/Screenshot 2023-05-08 153015.png)
