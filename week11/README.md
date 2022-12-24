このファイルはデータをバックアップする際に新規作成したものであり、大学時代のメモではない。

week11 はソートアルゴリズムの演習課題があったのだが、自分の書いたプログラムがどれくらい高速に動作するのかを実験するために大量の数値が書き込まれたファイルを用意していた。

```
$ du -ah week11 | sort -hr
```

```
38G week11
13G week11/sort_limit.dat
13G week11/numbers1G.dat
13G week11/glory.dat
1.2G  week11/numbers100M.dat
105M  week11/numbers10M.dat
9.6M  week11/numbers1M.dat
880K  week11/select_sort.dat
880K  week11/quick_sort.dat
880K  week11/numbers100Kdes.dat
880K  week11/numbers100Kasc.dat
880K  week11/numbers100K.dat
880K  week11/marge_sort.dat
880K  week11/insert_sort.dat
880K  week11/heap_sort.dat
880K  week11/bubble_sort.dat
88K week11/numbers10K.dat
16K week11/sort_limit
16K week11/11-4
12K week11/numbers1K.dat
12K week11/generate_big_numbers
12K week11/element_has_double
12K week11/descending_order
12K week11/check_time
12K week11/check_sort
12K week11/check_max_int
12K week11/check_malloc
12K week11/check_ary_memory
12K week11/11-3
12K week11/11-2ex
12K week11/11-2
12K week11/11-1
12K week11/.DS_Store
8.0K  week11/sort_limit.o
8.0K  week11/11-4.o
4.0K  week11/sort_limit.c
4.0K  week11/select_sort.o
4.0K  week11/select_sort.c
4.0K  week11/quick_sort.o
4.0K  week11/quick_sort.c
4.0K  week11/numbers5.dat
4.0K  week11/numbers4.dat
4.0K  week11/numbers3.dat
4.0K  week11/numbers2.dat
4.0K  week11/numbers1D.dat
4.0K  week11/numbers.dat
4.0K  week11/neo_merge.c
4.0K  week11/marge_sort.o
4.0K  week11/marge_sort.c
4.0K  week11/insert_sort.o
4.0K  week11/insert_sort.c
4.0K  week11/heap_sort.o
4.0K  week11/heap_sort.c
4.0K  week11/generate_big_numbers.c
4.0K  week11/element_has_double.c
4.0K  week11/descending_order.c
4.0K  week11/check_time.c
4.0K  week11/check_sort.c
4.0K  week11/check_max_int.c
4.0K  week11/check_malloc.c
4.0K  week11/check_ary_memory.c
4.0K  week11/bubble_sort.o
4.0K  week11/bubble_sort.c
4.0K  week11/11-4.c
4.0K  week11/11-3.c
4.0K  week11/11-2ex.c
4.0K  week11/11-2.c
4.0K  week11/11-1.c
```

上記のうち、ファイルサイズが 9.6M の `week11/numbers1M.dat` までは許容できるが、100M 以上のファイルはさすがに許容できなかったため、ファイル内の大部分を削除して管理することにした。

なお、許容できなかった 5 ファイルのもともとのそれぞれの行数は以下のとおりである。

```
$ wc -l sort_limit.dat
```

```
1000000001 sort_limit.dat
```

```
$ wc -l numbers1G.dat
```

```
1000000001 numbers1G.dat
```

```
$ wc -l glory.dat
```

```
1000000001 glory.dat
```

```
$ wc -l numbers100M.dat
```

```
100000001 numbers100M.dat
```

```
$ wc -l numbers10M.dat
```

```
10000001 numbers10M.dat
```

はじめはファイルサイズが 105M の `week11/numbers10M.dat` まではギリギリ許容できるかと思っていたが、GitHub では 1 ファイル 100M までという制約があったため push することができなかった。

```
Counting objects: 214, done.
Delta compression using up to 4 threads.
Compressing objects: 100% (201/201), done.
Writing objects: 100% (214/214), 49.77 MiB | 2.07 MiB/s, done.
Total 214 (delta 62), reused 0 (delta 0)
remote: Resolving deltas: 100% (62/62), done.
remote: error: Trace: 929a2ec4c68e3174c3199fc9e2858e08a69a4b051982d17da78859b3a58bea6d
remote: error: See http://git.io/iEPt8g for more information.
remote: error: File week11/numbers10M.dat is 104.90 MB; this exceeds GitHub's file size limit of 100.00 MB
remote: error: GH001: Large files detected. You may want to try Git Large File Storage - https://git-lfs.github.com.
To github.com:noraworld/isprogex2.git
 ! [remote rejected] main -> main (pre-receive hook declined)
error: failed to push some refs to 'git@github.com:noraworld/isprogex2.git'
```

そのため `week11/numbers10M.dat` もファイル内の大部分を削除した。

GitHub リポジトリのサイズ制限が 1G までというのは知っていたが、ファイルごとのサイズ制限があることは知らなかった。
