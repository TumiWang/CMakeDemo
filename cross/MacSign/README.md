#   创建手动创建证书

```sh
# 创建私钥
openssl genrsa -out private_key.pem 2048

# 创建证书请求
openssl req -new -key private_key.pem -out cert_req.csr

# 创建证书
openssl x509 -req -days 3650 -in cert_req.csr -signkey private_key.pem -out cert.pem
```

但实际上，使用界面化钥匙串工具创建