
= 開発環境の準備

== 必要なツールとソフトウェアのインストール

=== Canonical Multipass

コンテナを作成するために基本となるLinux環境が必要です。
今回は、UbuntuというLinux系のOS上でコンテナを開発します。
Ubuntuの開発支援をしているCanonical社が開発したCanonical Multipass(以下、Multipassと記載)は、Ubuntuの仮想環境を手軽に構築、管理することができるソフトウェアです。
Multipassは、Linux、macOS、Windowsに対応していますが、macOSではmultipassでUbuntu環境を構築し、WindowsではWSLで環境を構築するのが楽で良いでしょう。


== セットアップ

=== macOSでのセットアップ

Multipassをインストールします。

//cmd{
$ brew install --cask multipass
//}

起動状態の仮想マシンのことをインスタンスと呼びます。
インスタンスを作成します。
--cpus 1(1コア)、--disk 20G(20GB)、--memory 2G(RAM 2GB)、--name demo(demoという名前)、22.04(Ubuntu 22.04)という設定になっています。

//cmd{
$ multipass launch --cpus 1 --disk 20G --memory 2G --name demo 22.04
//}

作成したインスタンスのリストを表示して確認します。

//cmd{
$ multipass list
//}

container-demoフォルダをdemoインスタンスの~/container-runtimeにマウントします。

//cmd{
$ multipass mount container-demo demo:~/container-runtime
//}

作成したdemoインスタンスにログインします。

//cmd{
$ multipass shell demo
//}


=== Windowsでのインストール


//cmd{
$ multipass find
//}

