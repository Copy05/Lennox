# Lennox
The **Lennox** Operating system is a simple and lightweight project inspired by linux but without the unix.

# Building
You require a **Linux mashine** to build Lennox. WSL Won't build it correctly!

```bash
sudo apt update && sudo apt upgrade -y && sudo apt autoremove
sudo apt install nasm grub-common xorriso mtools
bash build.sh
```
