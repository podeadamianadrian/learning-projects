/** Scans all servers on the network.
 *
 * Returns the array of servers on the network.
 *
 * @param {NS} ns
 */
function scanner(ns) {
    let server_list = ["home"]
    for (let server of server_list) { for (let neighbor of ns.scan(server)) { if (!server_list.includes(neighbor)) { server_list.push(neighbor) } } } //BFS
    server_list.shift()
    return server_list
}

/** Filter servers.
 *
 * It will filter them based on max money and ram.
 *
 * It will output in multiple lists:
 *
 * All servers get in a detailed list.
 *
 * If max money > 0: hackable list.
 *
 * If ram > 0: sharable list.
 *
 * If max money = 0 and ram = 0: other list.
 *
 * @param {NS} ns
 * @param {string[]} list Array of server hostnames
*/
function filter(ns, list) {
    let detailed_list = [], hackable_list = [], sharable_list = [], other_list = []
    for (let server_name of list) {
        let server = {
            name: server_name,
            max_money: ns.getServerMaxMoney(server_name),
            min_security: ns.getServerMinSecurityLevel(server_name),
            ram: ns.getServerMaxRam(server_name),
            hack_level_req: ns.getServerRequiredHackingLevel(server_name),
            ports_req: ns.getServerNumPortsRequired(server_name),
            root: ns.hasRootAccess(server_name)
        }
        detailed_list.push(server)
        if (server.max_money > 0) { hackable_list.push(server) }
        if (server.ram > 0) { sharable_list.push(server) }
        if (server.max_money === 0 && server.ram === 0) { other_list.push(server) }
    }
    ns.write("data/detailed-list.json", JSON.stringify(detailed_list), 'w')
    ns.write("data/hackable-list.json", JSON.stringify(hackable_list), 'w')
    ns.write("data/sharable-list.json", JSON.stringify(sharable_list), 'w')
    ns.write("data/other-list.json", JSON.stringify(other_list), 'w')
}

/** @param {NS} ns */
export async function main(ns) {
    filter(ns, scanner(ns))
}
