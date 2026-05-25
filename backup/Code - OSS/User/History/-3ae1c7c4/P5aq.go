package main

import(
	"fmt"
	"net/http"
)

func home(w http.ResponseWriter, r *http.Request){
	html:=`<div style="background-color: #0d1117; color: #c9d1d9; font-family: 'Segoe UI', -apple-system, BlinkMacSystemFont, Roboto, sans-serif; padding: 50px 30px; border-radius: 16px; max-width: 650px; margin: 30px auto; box-shadow: 0 20px 40px rgba(0, 0, 0, 0.5); border: 1px solid #30363d; text-align: center;">
    
	<!-- Header / Call Sign -->
	<div style="font-size: 0.85rem; font-weight: 700; color: #58a6ff; letter-spacing: 3px; text-transform: uppercase; margin-bottom: 10px;">
			[ SITE_ID: VERTICAL_LIMIT ]
	</div>
	
	<!-- Main Title -->
	<h1 style="color: #ffffff; font-size: 2.5rem; font-weight: 800; margin: 0 0 8px 0; letter-spacing: -0.5px; text-transform: uppercase;">
			Mach Terminal
	</h1>
	
	<!-- Subtitle / Welcome Text -->
	<p style="color: #8b949e; font-size: 1.1rem; margin: 0 auto 30px auto; max-width: 480px; line-height: 1.5;">
			Welcome to the digital hangar. Curated by <strong style="color: #58a6ff;">GEMINI-03</strong> for high-fidelity aviation preservation, hardware deep-dives, and pure aerodynamic obsession.
	</p>

	<!-- Section Divider -->
	<div style="display: flex; align-items: center; justify-content: center; margin-bottom: 30px;">
			<div style="height: 1px; width: 40px; background-color: #30363d;"></div>
			<span style="font-size: 0.75rem; color: #8b949e; margin: 0 15px; letter-spacing: 2px; font-family: monospace;">CURRENT_EXHIBITS</span>
			<div style="height: 1px; width: 40px; background-color: #30363d;"></div>
	</div>

	<!-- Exhibit Grid / Items -->
	<div style="display: grid; gap: 16px; text-align: left;">
			
			<!-- Exhibit 1: Mitsubishi F-2 -->
			<div style="background-color: #161b22; padding: 20px; border-radius: 10px; border: 1px solid #30363d; border-left: 4px solid #1f6feb; display: flex; justify-content: space-between; align-items: start;">
					<div style="padding-right: 15px;">
							<h3 style="margin: 0 0 6px 0; font-size: 1.2rem; color: #f0f6fc; font-weight: 600;">
									Mitsubishi F-2A Viper Zero
							</h3>
							<p style="margin: 0; font-size: 0.9rem; color: #8b949e; line-height: 1.4;">
									JASDF maritime strike fighter. Features an advanced AESA radar array and co-cured composite wings optimized for low-altitude anti-ship profiles.
							</p>
					</div>
					<span style="font-size: 1.4rem; padding-top: 2px;">🇯🇵</span>
			</div>

			<!-- Exhibit 2: Northrop Grumman B-2 Spirit -->
			<div style="background-color: #161b22; padding: 20px; border-radius: 10px; border: 1px solid #30363d; border-left: 4px solid #f0883e; display: flex; justify-content: space-between; align-items: start;">
					<div style="padding-right: 15px;">
							<h3 style="margin: 0 0 6px 0; font-size: 1.2rem; color: #f0f6fc; font-weight: 600;">
									Northrop Grumman B-2 Spirit
							</h3>
							<p style="margin: 0; font-size: 0.9rem; color: #8b949e; line-height: 1.4;">
									The definitive flying wing stealth bomber. Engineered with RAM coatings and a split-rudder drag setup to completely eliminate vertical control surfaces.
							</p>
					</div>
					<span style="font-size: 1.4rem; padding-top: 2px; filter: drop-shadow(0 0 4px rgba(240, 136, 62, 0.4));">☢️</span>
			</div>

	</div>

	<!-- Footer Status Bar -->
	<div style="margin-top: 35px; padding-top: 20px; border-top: 1px solid #21262d; display: flex; justify-content: space-between; align-items: center; font-family: monospace; font-size: 0.75rem; color: #484f58;">
			<div>SYS_STATUS: NOMINAL</div>
			<div style="color: #238636; display: flex; align-items: center;">
					<span style="width: 6px; height: 6px; background-color: #238636; border-radius: 50%; display: inline-block; margin-right: 6px;"></span>
					TRANSONIC FEED ACTIVE
			</div>
	</div>

</div>`

fmt.Fprintln(w,html)
}

func main(){
	http.HandleFunc("/",home)
	fmt.Println("Server running on port 6969")
	http.ListenAndServe(":6969",nil)
}