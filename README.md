# Minitalk Projesi
## Proje Talimatları

- Executable dosyalarınızı `client` ve `server` olarak adlandırın.
- Programlar hiçbir şekilde beklenmedik şekilde kapanmamalıdır.
- Memory leaks olmamalıdır.
- Her program için bir global değişken kullanılabilir, ancak gerektiği yerlerde kullanılmalıdır.
- Zorunlu kısımda kullanabileceğiniz işlevler listelenmiştir.

## Zorunlu Bölüm

- Client ve server şeklinde bir iletişim programı oluşturmalısınız.
- Server başlatıldığında PID’sini yazdırmalıdır.
- Client, server PID'si ve gönderilecek string alarak çalıştırılmalıdır.
- Client, aldığı string'i server'a göndermelidir ve server bu string'i yazdırmalıdır.
- Server, aldığı string'i hızlı bir şekilde görüntülemelidir.
- Server, ardışık olarak birden fazla client'tan string alabilmelidir.
- Client ve server arasındaki iletişim yalnızca UNIX sinyalleri kullanılarak yapılmalıdır.