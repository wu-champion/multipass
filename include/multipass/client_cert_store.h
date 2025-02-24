/*
 * Copyright (C) 2018-2022 Canonical, Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef MULTIPASS_CLIENT_CERT_STORE_H
#define MULTIPASS_CLIENT_CERT_STORE_H

#include <multipass/cert_store.h>
#include <multipass/path.h>

#include <QList>
#include <QSslCertificate>

namespace multipass
{
class ClientCertStore : public CertStore
{
public:
    explicit ClientCertStore(const multipass::Path& cert_dir);
    void add_cert(const std::string& pem_cert) override;
    std::string PEM_cert_chain() const override;
    bool verify_cert(const std::string& pem_cert) override;
    bool empty() override;

private:
    bool verify_cert(const QSslCertificate& cert);

    Path cert_dir;
    QList<QSslCertificate> authenticated_client_certs;
};
} // namespace multipass
#endif // MULTIPASS_CLIENT_CERT_STORE_H
