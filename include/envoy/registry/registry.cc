#include "envoy/registry/registry.h"

namespace Envoy {

namespace Config {

class TypedMetadataFactory;

} // namespace Config

namespace Grpc {

class GoogleGrpcCredentialsFactory;

} // namespace Grpc

namespace Network {
namespace Address {

class Resolver;

} // namespace Address
} // namespace Network

namespace Router {

class HttpRouteTypedMetadataFactory;

} // namespace Router

namespace Server {
namespace Configuration {

class AccessLogInstanceFactory;
class CustomHealthCheckerFactory;
class DownstreamTransportSocketConfigFactory;
class NamedHttpFilterConfigFactory;
class NamedListenerFilterConfigFactory;
class NamedNetworkFilterConfigFactory;
class NamedUdpListenerFilterConfigFactory;
class ResourceMonitorFactory;
class StatsSinkFactory;
class TracerFactory;
class UpstreamTransportSocketConfigFactory;

} // namespace Configuration
} // namespace Server

namespace Singleton {

class Registration;

} // namespace Singleton

namespace Upstream {

class ClusterFactory;
class ClusterTypedMetadataFactory;
class RetryHostPredicateFactory;
class RetryPriorityFactory;

} // namespace Upstream

namespace Registry {

#define FACTORIES_IMPL(TYPE)                                                                       \
  template <> std::map<std::string, TYPE*>& FactoryRegistry<TYPE>::factories() {                   \
    static std::map<std::string, TYPE*>* factories = new std::map<std::string, TYPE*>;             \
    return *factories;                                                                             \
  }

FACTORIES_IMPL(Config::TypedMetadataFactory);
FACTORIES_IMPL(Grpc::GoogleGrpcCredentialsFactory); // fixfix ifdef
FACTORIES_IMPL(Network::Address::Resolver);
FACTORIES_IMPL(Router::HttpRouteTypedMetadataFactory);
FACTORIES_IMPL(Server::Configuration::AccessLogInstanceFactory);
FACTORIES_IMPL(Server::Configuration::CustomHealthCheckerFactory);
FACTORIES_IMPL(Server::Configuration::DownstreamTransportSocketConfigFactory);
FACTORIES_IMPL(Server::Configuration::NamedHttpFilterConfigFactory);
FACTORIES_IMPL(Server::Configuration::NamedListenerFilterConfigFactory);
FACTORIES_IMPL(Server::Configuration::NamedNetworkFilterConfigFactory);
FACTORIES_IMPL(Server::Configuration::NamedUdpListenerFilterConfigFactory);
FACTORIES_IMPL(Server::Configuration::ResourceMonitorFactory);
FACTORIES_IMPL(Server::Configuration::StatsSinkFactory);
FACTORIES_IMPL(Server::Configuration::TracerFactory);
FACTORIES_IMPL(Server::Configuration::UpstreamTransportSocketConfigFactory);
FACTORIES_IMPL(Singleton::Registration);
FACTORIES_IMPL(Upstream::ClusterFactory);
FACTORIES_IMPL(Upstream::ClusterTypedMetadataFactory);
FACTORIES_IMPL(Upstream::RetryHostPredicateFactory);
FACTORIES_IMPL(Upstream::RetryPriorityFactory);

} // namespace Registry
} // namespace Envoy
