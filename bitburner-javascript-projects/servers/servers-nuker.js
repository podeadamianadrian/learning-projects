/** @param {NS} ns */
export async function main(ns) {
    const duration_sleep = 2500
    const file = ns.read('data/detailed-list.json')
    const detailed_list = JSON.parse(file) //list is static because no new servers appear mid-game
    const program_list = [ //hardcoded list of programs and their codes because I don't have another option to get both
        { alias: "BruteSSH.exe", code: ns.brutessh },
        { alias: "FTPCrack.exe", code: ns.ftpcrack },
        { alias: "relaySMTP.exe", code: ns.relaysmtp },
        { alias: "HTTPWorm.exe", code: ns.httpworm },
        { alias: "SQLInject.exe", code: ns.sqlinject }
    ]
    while (1) {
        let existing_programs = 0
        for (let program of program_list) {
            if (ns.fileExists(program.alias)) { existing_programs++ }
        }
        for (let server of detailed_list) {
            if (!ns.hasRootAccess(server.name)) {
                if (existing_programs >= server.ports_req && ns.getHackingLevel() >= server.hack_level_req) {
                    for (let program of program_list) {
                        if (ns.fileExists(program.alias)) {
                            program.code(server.name)
                        }
                    }
                    ns.nuke(server.name)
                }
            }
        }
        await ns.sleep(duration_sleep)
    }
}
